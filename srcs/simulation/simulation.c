/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:31:40 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 21:33:11 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	simulation(t_table *table)
{
	table->philo_arr = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philo_arr)
		return (1);
	init_philo(table);
	start_threads(table);
	free_table(table);
	return (0);
}
