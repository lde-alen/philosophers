/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:20:01 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 18:58:01 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/**
 * @brief returns the current time in milliseconds.
 * 
 * @return long long 
 */
long long	timestamp(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000));
}

/**
 * @brief returns the time elapsed since the start of the program.
 * 
 * @param start 
 * @return long long 
 */
long long	exact_time(long long start)
{
	return (timestamp() - start);
}

/**
 * @brief sleeps for a given amount of time in milliseconds.
 * 
 * @param ms 
 * @param philo
 */
void	ft_usleep(long long ms, t_philo *philo)
{
	long long	time;

	time = timestamp();
	while (timestamp() - time < ms && check_death(philo) == FALSE)
		usleep(1000);
}
