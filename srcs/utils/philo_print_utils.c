/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:22:03 by lde-alen          #+#    #+#             */
/*   Updated: 2023/01/29 20:35:01 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/**
 * @brief Function that prints the current time, the id of the philosopher his
 * state. In order to avoid data races the print_lock is locked before printing
 * and unlocked right after.
 * 
 * @param philo 
 * @param str 
 */
void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%lld %d %s\n", exact_time(philo->table->start_time), \
	philo->id + 1, str);
	pthread_mutex_unlock(&philo->table->print_lock);
}

/**
 * @brief This function forces all threads to essentially pass by a single point.
 * it checks the current state of the philosopher and calls the print function
 * accordingly.
 * 
 * @param philo 
 * @param flag 
 */
void	ft_print_safe(t_philo *philo, int flag)
{
	if (check_death_status(philo) == 0 && flag != DIED)
	{
		if (flag == EATING)
			ft_print(philo, "is eating");
		else if (flag == SLEEPING)
			ft_print(philo, "is sleeping");
		else if (flag == THINKING)
			ft_print(philo, "is thinking");
		else if (flag == FORK)
			ft_print(philo, "has taken a fork");
	}
}
