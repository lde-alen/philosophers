/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:40:25 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:42:06 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*monitoring(void *philo_arr)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)philo_arr;
	while (check_death(&philo[i]) == 0)
	{
		pthread_mutex_lock(&philo[i].last_meal_lock);
		if (exact_time(philo[i].last_meal) > philo[i].table->time_to_die && \
			philo[i].last_meal != 0)
		{
			pthread_mutex_unlock(&philo[i].last_meal_lock);
			pthread_mutex_lock(&philo[i].table->death_mutex);
			if (philo[i].table->dead == FALSE)
				ft_print(&philo[i], "died");
			philo[i].table->dead = TRUE;
			pthread_mutex_unlock(&philo[i].table->death_mutex);
		}
		else
			pthread_mutex_unlock(&philo[i].last_meal_lock);
		usleep(500);
		i++;
	}
	return (NULL);
}

