/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:31:40 by lde-alen          #+#    #+#             */
/*   Updated: 2023/02/02 21:10:02 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/**
 * @brief 
 * 		main function in charge to start the simulation. It calls the function
 * that initializes the philo struct and the function that starts the threads.
 * @return int 
 */
int	simulation(t_table *table)
{
	init_philo(table);
	start_threads(table);
	free_table(table);
	return (0);
}
