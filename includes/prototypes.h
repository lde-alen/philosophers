/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:47 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 14:16:09 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/**
 * 	PROTOTYPES
 * 
 */
void	ft_fputchar(char c);
void	ft_fputstr(char *str);

int		check_nb_args(int ac);
int		is_num(char **str);
int		check_args(int ac, char **av);

#endif
