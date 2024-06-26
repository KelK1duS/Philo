/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:57:40 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:47:32 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

t_bool	print_fork(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->arg->m_print);
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->m_print);
		return (FALSE);
	}
	printf("%06li %zu has taken a fork\n",
		diff_timeval(t, philo->arg->start) / MS,
		philo->id);
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}

t_bool	print_eating(t_tv t, t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->m_print);
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->m_print);
		return (FALSE);
	}
	printf("%06li %zu is eating\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}

t_bool	print_sleeping(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->arg->m_print);
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->m_print);
		return (FALSE);
	}
	printf("%06li %zu is sleeping\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}

t_bool	print_thinking(t_philo *philo)
{
	t_tv	t;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->arg->m_print);
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->m_print);
		return (FALSE);
	}
	printf("%06li %zu is thinking\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}

t_bool	print_died(t_tv t, t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->m_print);
	printf("%06li %zu died\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id);
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}
