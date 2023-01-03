/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isalgar <isalgar@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:01:15 by isalgar           #+#    #+#             */
/*   Updated: 2023/01/03 19:01:17 by isalgar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	size_t			philo_id;
	size_t			left_fork;
	size_t			right_fork;
	size_t			last_meal_time;
	struct s_arg	*arg;
	int				meals;
	size_t			time;
	pthread_t		th;
}					t_philo;

typedef struct s_arg
{
	int				nbr_philo;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meal;
	struct s_philo	*philo;
	int				dead;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	meals_mutex;
}					t_arg;

int					main(int ac, char **av);
int					ft_ac_av_controller(char **av);
int					ft_atoi(const char *str);
int					ft_is_digit(char *str);
size_t				ft_time(void);
void				ft_usleep(int ms);
int					ft_take_forks(t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_sleep(t_philo *philo);
int					start_threads(t_arg *arg);
int					ft_init_arg(t_arg *arg, int ac, char **av);
void				ft_messager(t_philo *philo, int chk);
void				ft_clear(t_arg *arg);

#endif
