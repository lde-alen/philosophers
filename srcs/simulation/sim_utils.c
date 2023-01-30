/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:42:21 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 20:19:36 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_check_meal(t_philo *philo)
{
	int	i;
	int	food_coma;

	i = 0;
	food_coma = 0;
	while (i < philo->total_nb_philo && !food_coma)
	{
		pthread_mutex_lock(&philo->table->philo_arr[i].meal_lock);
		if (philo->table->nb_meals == -1
			|| philo->table->philo_arr[i].nb_meals < philo->table->nb_meals)
			food_coma++;
		pthread_mutex_unlock(&philo->table->philo_arr[i].meal_lock);
		i++;
	}
	return (food_coma);
}

int	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_mutex);
	if (philo->table->end == TRUE)
	{
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
	return (0);
}
