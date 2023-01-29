/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:47 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/28 19:27:01 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/**
 * 	PROTOTYPES
 * 
 */
void		ft_fputchar(char c);
void		ft_fputstr(char *str);
int			check_nb_args(int ac);
int			check_int_args(char **av);
int			ft_isdigit(char c);
size_t		ft_strlen(char *str);
int			check_size(char **av);
int			philo(t_table *table);
int			init_table(t_table *table, char **av);
int			is_num(char **str);
int			ft_atoi(const char *str);
void		ft_usleep(long long ms, t_philo *philo);
long long	timestamp(void);
int			check_args(int ac, char **av);
int			init_philo(t_table *table, t_philo *philo);
int			sim_start(t_table *table);
int			thread_create(t_table *table, t_philo *philo);
void		*routine(void *philo_cpy);
void		ft_print(t_philo *philo, char *str);
long long	exact_time(long long start);
void		ft_print_safe(t_philo *philo, int flag);
int			check_death(t_philo *philo);
int			chew_baka(t_philo *philo);
void		ft_america(t_table *table);
int			ft_check_meal(t_philo *philo);

#endif
