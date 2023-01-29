/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:08:06 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:46:53 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	thread_init(t_table *table)
{
	int		i;

	i = -1;
	if (pthread_mutex_init(&table->print_lock, NULL)
		|| pthread_mutex_init(&table->death_mutex, NULL)
		|| pthread_mutex_init(&table->death_mutex, NULL))
		return (ft_fputstr("ERROR: mutex init failed.\n"), 1);
	while (++i < table->nb_philo)
	{
		table->forks[i] = 1;
		if (pthread_mutex_init(&table->forks_mutex[i], NULL))
			return (ft_fputstr("ERROR: mutex init failed.\n"), 1);
	}
	return (0);
}

int	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philo[i], NULL))
			return (ft_fputstr("ERROR: thread join failed.\n"), 1);
		i++;
	}
	return (0);
}

int	start_philos(t_table *table, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		usleep(500);
		if (pthread_create(&table->philo[i], NULL, routine, &philo[i]))
			return (ft_fputstr("ERROR: thread creation failed.\n"), 1);
		i++;
	}
	return (0);
}

int	start_reaper(t_reaper *reaper)
{
	pthread_t	grim_reaper;

	grim_reaper = (pthread_t)malloc(sizeof(pthread_t));
	if (pthread_create(&grim_reaper, NULL, monitoring, reaper->philo_arr))
		return (ft_fputstr("ERROR: thread creation failed.\n"), 1);
	return (0);
}

int	start_threads(t_table *table, t_philo *philo)
{
	t_reaper	reaper;

	table->start_time = timestamp();
	if (thread_init(table))
		return (1);
	start_philos(table, philo);
	start_reaper(&reaper);
	join_threads(table);
	return (0);
}
