/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_tasks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:41:10 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:54:42 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	eat2(t_philo *philo)
{
	philo->table->forks[philo->r_fork] = FALSE;
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->r_fork]);
	ft_print_safe(philo, FORK);
	ft_print_safe(philo, FORK);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->last_meal_lock);
	ft_print_safe(philo, EATING);
	ft_usleep(philo->table->time_to_eat, philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_lock(&philo->table->forks_mutex[philo->r_fork]);
	philo->table->forks[philo->r_fork] = TRUE;
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->r_fork]);
	pthread_mutex_lock(&philo->table->forks_mutex[philo->id]);
	philo->table->forks[philo->id] = TRUE;
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->id]);
	return (1);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks_mutex[philo->id]);
	if (philo->table->forks[philo->id] == TRUE)
	{
		philo->table->forks[philo->id] = FALSE;
		pthread_mutex_unlock(&philo->table->forks_mutex[philo->id]);
		pthread_mutex_lock(&philo->table->forks_mutex[philo->r_fork]);
		if (philo->table->forks[philo->r_fork] == TRUE)
			return (eat2(philo));
		else
		{
			pthread_mutex_unlock(&philo->table->forks_mutex[philo->r_fork]);
			pthread_mutex_lock(&philo->table->forks_mutex[philo->id]);
			philo->table->forks[philo->id] = TRUE;
			pthread_mutex_unlock(&philo->table->forks_mutex[philo->id]);
			return (0);
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks_mutex[philo->id]);
		return (0);
	}
	return (0);
}

/**
 * @brief 
 * 
 * @param philo_cpy 
 * @return void* 
 */
void	*routine(void *philo)
{
	t_philo		*philo_cpy;

	philo_cpy = philo;
	while (check_death(philo_cpy) == 0)
	{
		while (eat(philo_cpy) == 0 && check_death(philo_cpy) == 0)
			;
		ft_print_safe(philo_cpy, SLEEPING);
		ft_usleep(philo_cpy->table->time_to_sleep, philo_cpy);
		ft_print_safe(philo_cpy, THINKING);
	}
	return (NULL);
}