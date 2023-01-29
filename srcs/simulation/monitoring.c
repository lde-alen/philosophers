/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:40:25 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 23:22:30 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	monitoring(t_philo *philo)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (!check_death_status(philo))
	{
		usleep(100);
		pthread_mutex_lock(&philo->last_meal_lock);
		if (exact_time(philo->last_meal) > philo->table->time_to_die)
		{
			pthread_mutex_unlock(&philo->last_meal_lock);
			pthread_mutex_lock(&philo->table->death_mutex);
			if (philo->table->dead == FALSE)
				ft_print(philo, "died");
			philo->table->dead = TRUE;
			pthread_mutex_unlock(&philo->table->death_mutex);
			ret = 1;
		}
		else
			pthread_mutex_unlock(&philo->last_meal_lock);
		i++;
	}
	return (ret);
}
