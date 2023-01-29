/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:37:51 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 13:44:10 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief prints a caracter to the standard error output.
 * 
 * @param char c 
 * @return void
 */
void	ft_fputchar(char c)
{
	write(2, &c, 1);
}

/**
 * @brief prints a string to the standard error output.
 * 
 * @param string
 */
void	ft_fputstr(char *str)
{
	while (*str)
		ft_fputchar(*str++);
}
