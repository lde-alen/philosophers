/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:42:21 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:48:38 by lde-alen         ###   ########.fr       */
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

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->dead == TRUE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	else if (ft_check_meal(philo))
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


