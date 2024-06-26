/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_emoji.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:24:47 by bedarenn          #+#    #+#             */
/*   Updated: 2024/05/22 10:49:41 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_bool	print_fork(t_philo *philo)
{	
	t_tv	t;
	t_ltime	diff;

	gettimeofday(&t, NULL);
	pthread_mutex_lock(&philo->arg->m_print);
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->m_print);
		return (FALSE);
	}
	printf("%06li | %zu | has taken a fork %s\n",
		diff = diff_timeval(t, philo->arg->start) / 1000,
		philo->id,
		"\xF0\x9F\x8D\xB4");
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
	printf("%06li | %zu | is eating        %s\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id,
		"\xF0\x9F\x8D\x9C");
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
	printf("%06li | %zu | is sleeping      %s\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id,
		"\xF0\x9F\x92\xA4");
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
	printf("%06li | %zu | is thinking      %s\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id,
		"\xF0\x9F\x92\xA1");
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}

t_bool	print_died(t_tv t, t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->m_print);
	printf("%06li | %zu | died             %s\n",
		diff_timeval(t, philo->arg->start) / 1000,
		philo->id,
		"\xF0\x9F\x92\x80");
	pthread_mutex_unlock(&philo->arg->m_print);
	return (TRUE);
}
