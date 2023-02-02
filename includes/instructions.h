/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:48:52 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:48:55 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

/**
 * MACROS for the formatted and organized Instructions.
 * 
 */
# define SYNTAX	"\n								\033[4mINSTRUCTIONS:\033[0m\n\n\
	\033[4mERROR: Invalid Syntax:\033[0m\n\n	\033[4mUsage:\033[0m\n\
		./philo \"number_of_philosophers\" \"time_to_die\" \"time_to_eat\" \
\"time_to_sleep\" [number_of_times_each_philosopher_must_eat]\n"

# define DESC		"\n\n	\033[4mDescription:\033[0m\n\n		\"number_of_philosophers\":						The number of philosophers\
and also the number of forks.\n\n		\"time_to_die\" (in milliseconds):					If a philosopher\
 didn’t start eating time_to_die milliseconds since the beginning of their\
 last meal or the beginning of the simulation, they die\n\n\
		\"time_to_eat\" (in milliseconds):					The time it takes for a philosopher to eat.\
During that time, they will need to hold two forks.\n\n\
		\"time_to_sleep\" (in milliseconds):					The time a philosopher will spend sleeping.\
\n\n		\"number_of_times_each_philosopher_must_eat\" (optional argument):	If all philosophers have eaten at\
least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, \
the simulation stops when a philosopher dies.\n"

# define EX			"\n	\033[4mExample:\033[0m\n\
		./philo 100 800 200 200\n\n"

# define NOT_NUM	"\nERROR: One or more arguments are invalid, please ensure \
all the argument are numbers.\n"

#endif
