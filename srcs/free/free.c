/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:45:46 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 21:31:59 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	free(table->forks);
	while (i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->forks_mutex[i]);
		i++;
	}
	free (table->forks_mutex);
	free (table->philo_arr);
	pthread_mutex_destroy(&table->print_lock);
}
