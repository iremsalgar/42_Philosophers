/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:59:22 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:00:41 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	control_philo(t_arg *arg)
{
	arg->philo->time = ft_time();
	if (arg->nbr_philo == 1)
	{
		printf("%zu\t%zu has taken a fork\n", ft_time() - arg->philo->time,
			arg->philo->philo_id);
		ft_usleep(arg->time_to_die);
		printf("%zu\t%zu died\n", ft_time() - arg->philo->time,
			arg->philo->philo_id);
		return (1);
	}
	return (0);
}

static void	ft_check_arg(void)
{
	printf("\x1b[35m _____________________________________ \x1b[0m \n");
	printf("\x1b[35m|    Please enter 4 or 5 arguments    |\x1b[0m \n");
	printf("\x1b[35m|_____________________________________|\x1b[0m \n");
	printf("\x1b[35m|     [1][Number of philosophers]     |\x1b[0m \n");
	printf("\x1b[35m|     [2][Time to die]                |\x1b[0m \n");
	printf("\x1b[35m|     [3][Time to eat]                |\x1b[0m \n");
	printf("\x1b[35m|     [4][Time to sleep]              |\x1b[0m \n");
	printf("\x1b[35m|     [5][Number of meals]            |\x1b[0m \n");
	printf("\x1b[35m|_____________________________________|\x1b[0m \n");
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac == 5 || ac == 6)
	{
		if (ft_ac_av_controller(av))
			return (1);
		if (ft_init_arg(&arg, ac, av))
			return (1);
		if (control_philo(&arg))
			return (1);
		if (start_threads(&arg))
			return (1);
		ft_clear(&arg);
	}
	else if (ac < 5 || ac > 6)
	{
		ft_check_arg();
		return (1);
	}
	return (0);
}
