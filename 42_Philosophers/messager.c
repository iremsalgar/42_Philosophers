/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:58 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:01:00 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_messager(t_philo *philo, int chk)
{
	long	time;

	pthread_mutex_lock(&philo->arg->write_mutex);
	pthread_mutex_lock(&philo->arg->die_mutex);
	if (!philo->arg->dead)
	{
		time = ft_time() - philo->time;
		if (chk == 1)
			printf("%ld %ld \x1b[32m is eating\x1b[0m \n", time,
				(philo->philo_id));
		if (chk == 2)
			printf("%ld %ld \x1b[34m is sleeping\x1b[0m \n", time,
				philo->philo_id);
		if (chk == 3)
			printf("%ld %ld \x1b[33m is thinking\x1b[0m \n", time,
				philo->philo_id);
	}
	pthread_mutex_unlock(&philo->arg->die_mutex);
	pthread_mutex_unlock(&philo->arg->write_mutex);
}
