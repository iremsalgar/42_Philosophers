#include "philo.h"

void	ft_take_fork(t_philosopher *philo)
{
    long time;

    pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print_lock);
	if ((philo->id) % 2 == 0 && philo->id + 1 != philo->nbr_philo)
	{
		if (philo->stop != 1)
		{
            time = ft_time() - philo->start_time;
			printf("%ld %d has taken a fork\n", time, philo->id + 1);
			printf("%ld %d has taken a fork\n", time, philo->id + 1);
		}
		pthread_mutex_unlock(&philo->print_lock);
	}
	else if(philo->stop != 1)
	{
        time = ft_time() - philo->start_time;
        printf("%ld %d has taken a fork\n", time, philo->id + 1);
		printf("%ld %d has taken a fork\n", time, philo->id + 1);
        pthread_mutex_unlock(&philo->print_lock);
    }
}