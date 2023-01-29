/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:31:29 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 14:14:20 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief error
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ft_fputstr(SYNTAX), ft_fputstr(DESC), ft_fputstr(EX), 1);
	if (is_num(++av))
		return (ft_fputstr(NOT_NUM), 1);
	return (0);
}
