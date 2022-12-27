#include "philo.h"

void	ft_eat(t_philosopher *philo)
{
    long time;

	pthread_mutex_lock(&philo->print_lock);
	time = ft_time() - philo->start_time;
    printf("%ld %d \x1b[32m is eating\x1b[0m \n", time, (philo->id + 1));
	pthread_mutex_unlock(&philo->print_lock);
	philo->meals_allowed += 1;
	philo->last_meal_time = ft_time();
	printf("*\n");
	ft_usleep(philo->time_to_eat); //yemek yeme süresi bekleme yapılır
	//pthread_mutex_unlock(philo->left_fork);
	printf("1\n");
	//pthread_mutex_unlock(philo->right_fork);
	printf("b\n");
}

void	ft_sleep(t_philosopher *philo)
{
    long time;

	pthread_mutex_lock(&philo->print_lock);
	time = ft_time() - philo->start_time;
    printf("%ld %d \x1b[34m is sleeping\x1b[0m \n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->print_lock);
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philosopher *philo)
{
    long time;

	pthread_mutex_lock(&philo->print_lock);
	time = ft_time() - philo->start_time;
    printf("%ld %d \x1b[33m is thinking\x1b[0m \n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->print_lock);
}

void	ft_died(t_philosopher *philo, int i)
{
    long time;

	philo->arg->dead = 1;
	pthread_mutex_lock(&philo->print_lock);
    time = ft_time() - philo->start_time;
	printf("%ld %d \x1b[31m died\x1b[0m \n", time, philo[i].id + 1);
	i = 0;
	while (i < philo[i].nbr_philo)
		philo[i++].stop = 1;
}