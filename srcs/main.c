/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:47:49 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 17:44:48 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/**
 * @brief main node that calls for the argument check to check for invalid
 * parameters. Then calls the funcitons that initializes the shared structure
 * and the philo structures.
 * @param argc 
 * @param argv 
 * @return int | 1 if error occured, 0 if no error.
 */
int	main(int ac, char **av)
{
	t_table		table;

	if (check_args(ac, av) || init_table(&table, av))
		return (1);
	else
		return (simulation(&table), 0);
}
