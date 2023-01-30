/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:47 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/30 12:58:47 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/**
 * INCLUDES REQUIRED
 * 
 */
# include <pthread.h>

/**
 * STRUCTURES
 * 
 */
typedef struct s_philo
{
	int				id;
	int				nb_meals;
	pthread_mutex_t	meal_lock;
	long long		last_meal;
	pthread_mutex_t	last_meal_lock;
	int				r_fork;
	int				total_nb_philo;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals;
	long long			start_time;
	int					end;
	int					*forks;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		death_mutex;
	pthread_t			*philo;
	t_philo				*philo_arr;
}	t_table;

#endif
