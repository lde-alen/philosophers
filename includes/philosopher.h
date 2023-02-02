/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:22:30 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 21:55:16 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/**
 * INCLUDES
 * 
 */
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "macros.h"
# include "structs.h"
# include "instructions.h"

/**
 * 	PROTOTYPES
 * 
 */
void		ft_fputchar(char c);
void		ft_fputstr(char *str);
void		*routine(void *philo);
void		ft_print(t_philo *philo, char *str);
void		free_table(t_table *table);
void		ft_print_safe(t_philo *philo, int flag);
void		ft_usleep(long long ms, t_philo *philo);

int			monitoring(t_philo *philo);
int			start_philos(t_table *table);
int			start_reaper(t_table *table);
int			ft_isdigit(char c);
int			ft_atoi(const char *str);
int			check_death_status(t_philo *philo);
int			check_nb_args(int ac);
int			is_num(char **str);
int			check_args(int ac, char **av);
int			init_table(t_table	*table, char **av);
int			init_philo(t_table *table);
int			thread_init(t_table *table);
int			join_threads(t_table *table);
int			start_threads(t_table *table);
int			simulation(t_table *table);
int			eat(t_philo *philo);
int			eat2(t_philo *philo);
int			ft_check_meal(t_philo *philo);

long long	timestamp(void);
long long	exact_time(long long start);

size_t		ft_strlen(char *str);

#endif
