/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:21 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:00:24 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&arg->write_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&arg->die_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&arg->meals_mutex, NULL))
		return (1);
	arg->fork_mutex = malloc(sizeof(pthread_mutex_t) * arg->nbr_philo);
	if (!arg->fork_mutex)
		return (1);
	i = -1;
	while (++i < arg->nbr_philo)
		if (pthread_mutex_init(&arg->fork_mutex[i], NULL))
			return (1);
	return (0);
}

static void	ft_init_philo(t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->nbr_philo)
	{
		arg->philo[i].philo_id = i + 1;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->nbr_philo;
		arg->philo[i].last_meal_time = 0;
		arg->philo[i].arg = arg;
		arg->philo[i].meals = 0;
		arg->dead = 0;
	}
}

int	ft_init_arg(t_arg *arg, int ac, char **av)
{
	arg->nbr_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->dead = 0;
	if (ac == 6)
		arg->nbr_of_meal = ft_atoi(av[5]);
	if (ac == 5)
		arg->nbr_of_meal = -1;
	if (arg->nbr_philo < 1)
		return (1);
	arg->philo = malloc(sizeof(t_philo) * arg->nbr_philo);
	if (!arg->philo)
		return (1);
	ft_init_philo(arg);
	if (ft_init_mutex(arg))
		return (1);
	return (0);
}
