/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:07:01 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:29:10 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_table(t_table	*table, t_reaper *reaper, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->dead = 0;
	reaper->philo_arr = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo);
	table->philo = (pthread_t *)malloc(sizeof(pthread_t) * table->nb_philo);
	table->forks = (int *)malloc(sizeof(int) * table->nb_philo);
	table->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->nb_philo);
	if (!table->forks || !table->philo || !table->forks_mutex
		|| !reaper->philo_arr)
		return (ft_fputstr("ERROR: malloc failed.\n"), 1);
	table->nb_meals = -1;
	if (av[5])
		table->nb_meals = ft_atoi(av[5]);
	return (thread_init(table), 0);
}

int	init_philo(t_table *table, t_philo *philo, t_reaper *reaper)
{
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&philo[i].meal_lock, NULL);
		pthread_mutex_init(&philo[i].last_meal_lock, NULL);
		if (pthread_mutex_init(&philo[i].meal_lock, NULL)
			|| pthread_mutex_init(&philo[i].meal_lock, NULL))
			return (ft_fputstr("ERROR: mutex init failed.\n"), 1);
		philo[i].table = table;
		philo[i].id = i;
		philo[i].r_fork = i + 1;
		if (i == table->nb_philo - 1)
			philo[i].r_fork = 0;
		philo[i].nb_meals = 0;
		philo[i].last_meal = 0;
		reaper->philo_arr[i] = philo[i];
		i++;
	}
	return (0);
}