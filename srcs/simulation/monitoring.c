/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:40:25 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 13:00:36 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	meal_end(t_philo *philo)
{			
	pthread_mutex_lock(&philo->table->death_mutex);
	philo->table->end = TRUE;
	pthread_mutex_unlock(&philo->table->death_mutex);
	return (1);
}

int	monitoring(t_philo *philo)
{
	int	i;

	i = 0;
	while (!check_death_status(philo))
	{
		usleep(100);
		pthread_mutex_lock(&philo->last_meal_lock);
		if (exact_time(philo->last_meal) > philo->table->time_to_die)
		{
			pthread_mutex_unlock(&philo->last_meal_lock);
			pthread_mutex_lock(&philo->table->death_mutex);
			if (philo->table->end == FALSE)
				ft_print(philo, "died");
			philo->table->end = TRUE;
			pthread_mutex_unlock(&philo->table->death_mutex);
			return (meal_end(philo));
		}
		else if (ft_check_meal(philo) == TRUE)
			return (pthread_mutex_unlock(&philo->last_meal_lock),
				meal_end(philo));
		else
			pthread_mutex_unlock(&philo->last_meal_lock);
		i++;
	}
	return (0);
}
