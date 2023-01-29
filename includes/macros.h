/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:07:54 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:50:50 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/**
 * TRUE / FALSE
 * 
 */
enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

/**
 * PHILOSOPHER STATES
 * 
 */
enum e_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	FORK = 3,
	DIED = 4,
}	t_state;

#endif
