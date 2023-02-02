/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:40:25 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 20:12:28 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	monitoring(t_philo *philo)
{
	usleep(100);
	pthread_mutex_lock(&philo->last_meal_lock);
	if (exact_time(philo->last_meal) > philo->table->time_to_die
		|| (philo->table->nb_meals != -1 && !ft_check_meal(philo)))
	{
		pthread_mutex_unlock(&philo->last_meal_lock);
		pthread_mutex_lock(&philo->table->death_mutex);
		if (philo->table->end == FALSE)
			ft_print(philo, "died");
		philo->table->end = TRUE;
		pthread_mutex_unlock(&philo->table->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_meal_lock);
	return (0);
}
