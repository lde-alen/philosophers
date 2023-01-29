/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:28:35 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 14:56:09 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief returns the current time in milliseconds.
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
