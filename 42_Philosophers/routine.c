/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:01:47 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:01:49 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	philo->time = ft_time();
	pthread_mutex_lock(&philo->arg->meals_mutex);
	philo->last_meal_time = philo->time;
	pthread_mutex_unlock(&philo->arg->meals_mutex);
	while (1)
	{
		if (philo->arg->nbr_of_meal != -1
			&& philo->meals == philo->arg->nbr_of_meal)
			break ;
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->arg->die_mutex);
		if (philo->arg->dead)
		{
			pthread_mutex_unlock(&philo->arg->die_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->arg->die_mutex);
	}
	return (NULL);
}

static int	ft_watch_utils(t_arg *arg, int i)
{
	pthread_mutex_lock(&arg->meals_mutex);
	if (ft_time() - arg->philo[i].last_meal_time >= arg->time_to_die)
	{
		pthread_mutex_unlock(&arg->meals_mutex);
		pthread_mutex_lock(&arg->die_mutex);
		arg->dead = 1;
		pthread_mutex_unlock(&arg->die_mutex);
		pthread_mutex_lock(&arg->write_mutex);
		if (arg->nbr_of_meal != arg->philo[i].meals)
			printf("%zu\t%zu died\n", ft_time() - arg->philo[i].time,
				arg->philo[i].philo_id);
		pthread_mutex_unlock(&arg->write_mutex);
		return (1);
	}
	else
		return (0);
}

static void	ft_watch(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->nbr_philo)
	{
		if (ft_watch_utils(arg, i))
			break ;
		else
			pthread_mutex_unlock(&arg->meals_mutex);
		i++;
		if (i == arg->nbr_philo)
			i = 0;
		usleep(50);
	}
}

int	start_threads(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->nbr_philo)
	{
		if (pthread_create(&arg->philo[i].th, NULL, &routine, &arg->philo[i]))
			return (1);
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < arg->nbr_philo)
	{
		if (pthread_create(&arg->philo[i].th, NULL, &routine, &arg->philo[i]))
			return (1);
		i += 2;
		usleep(50);
	}
	ft_watch(arg);
	i = -1;
	while (++i < arg->nbr_philo)
		if (pthread_join(arg->philo[i].th, NULL))
			return (1);
	return (0);
}
