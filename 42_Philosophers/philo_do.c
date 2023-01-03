/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:01:28 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:01:30 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	ft_messager(philo, 2);
	ft_usleep(philo->arg->time_to_sleep);
	ft_messager(philo, 3);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	ft_messager(philo, 1);
	if (philo->arg->nbr_of_meal != -1)
		philo->meals += 1;
	pthread_mutex_lock(&philo->arg->meals_mutex);
	philo->last_meal_time = ft_time();
	pthread_mutex_unlock(&philo->arg->meals_mutex);
	ft_usleep(philo->arg->time_to_eat);
	pthread_mutex_unlock(&philo->arg->fork_mutex[philo->right_fork]);
	pthread_mutex_unlock(&philo->arg->fork_mutex[philo->left_fork]);
	return (0);
}

static void	ft_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->arg->write_mutex);
	pthread_mutex_lock(&philo->arg->die_mutex);
	if (!philo->arg->dead)
		printf("%zu\t%zu %s\n", ft_time() - philo->time, philo->philo_id,
			message);
	pthread_mutex_unlock(&philo->arg->die_mutex);
	pthread_mutex_unlock(&philo->arg->write_mutex);
}

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->fork_mutex[philo->right_fork]);
	ft_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->arg->fork_mutex[philo->left_fork]);
	ft_message(philo, "has taken a fork");
	return (0);
}
