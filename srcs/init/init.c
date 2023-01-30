/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:07:01 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 12:50:03 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_table(t_table	*table, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->end = 0;
	table->philo_arr = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo);
	table->philo = (pthread_t *)malloc(sizeof(pthread_t) * table->nb_philo);
	table->forks = (int *)malloc(sizeof(int) * table->nb_philo);
	table->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->nb_philo);
	if (!table->forks || !table->philo || !table->forks_mutex
		|| !table->philo_arr)
		return (ft_fputstr("ERROR: malloc failed.\n"), 1);
	table->nb_meals = -1;
	if (av[5])
		table->nb_meals = ft_atoi(av[5]);
	return (thread_init(table), 0);
}

int	init_philo(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_init(&table->philo_arr[i].meal_lock, NULL);
		pthread_mutex_init(&table->philo_arr[i].last_meal_lock, NULL);
		if (pthread_mutex_init(&table->philo_arr[i].meal_lock, NULL)
			|| pthread_mutex_init(&table->philo_arr[i].meal_lock, NULL))
			return (ft_fputstr("ERROR: mutex init failed.\n"), 1);
		table->philo_arr[i].table = table;
		table->philo_arr[i].id = i;
		table->philo_arr[i].r_fork = i + 1;
		if (i == table->nb_philo - 1)
			table->philo_arr[i].r_fork = 0;
		table->philo_arr[i].nb_meals = 0;
		table->philo_arr[i].last_meal = 0;
		table->philo_arr[i].total_nb_philo = table->nb_philo;
		i++;
	}
	return (0);
}
