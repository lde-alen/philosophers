/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:52:54 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 14:17:59 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief  takes the number of arguments and checks if it is between 5 and 6.
 * 
 * @param ac 
 * @return int 0 if false, 1 if true.
 */
int	check_nb_args(int ac)
{
	if (ac < 5 || ac > 6)
		return (FALSE);
	else
		return (TRUE);
}

/**
 * @brief Checks if all the caracter in the string are digits.
 * 
 * @param str 
 * @return int return 1 if not a number, 0 if it is.
 */
int	is_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
