/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:31:40 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 19:53:44 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	simulation(t_table *table)
{
	t_philo		*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
		return (1);
	init_philo(table, philo);
	start_threads(table, philo);
	free_table(table);
	free (philo);
	return (0);
}
