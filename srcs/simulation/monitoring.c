/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:40:25 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 15:35:46 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*monitoring(t_philo *philo)
{
	int			i;

	i = 0;
	while (check_death(philo) == 0)
	{
		pthread_mutex_lock(&philo->last_meal_lock);
		if (exact_time(philo->last_meal) > philo->table->time_to_die && \
			philo->last_meal != 0)
		{
			pthread_mutex_unlock(&philo->last_meal_lock);
			pthread_mutex_lock(&philo->table->death_mutex);
			if (philo->table->dead == FALSE)
				ft_print(philo, "died");
			philo->table->dead = TRUE;
			pthread_mutex_unlock(&philo->table->death_mutex);
		}
		else
			pthread_mutex_unlock(&philo->last_meal_lock);
		usleep(500);
		i++;
	}
	return (NULL);
}

