/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:42:21 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 23:25:03 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_check_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->nb_meals == philo->table->nb_meals)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

int	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->dead == TRUE || ft_check_meal(philo))
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (0);
	}
}
