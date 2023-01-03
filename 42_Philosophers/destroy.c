/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:00:10 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:00:11 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear(t_arg *arg)
{
	if (arg->philo)
		free(arg->philo);
	pthread_mutex_destroy(&arg->write_mutex);
	pthread_mutex_destroy(arg->fork_mutex);
	pthread_mutex_destroy(&arg->die_mutex);
}
