#include "philo.h"

void *ft_watch_philo(void *arg)
{
    t_philosopher *philo;
    long time_now;
    int i;
    int loop;

    philo = (t_philosopher *)arg;
    i = 0;
    loop = 1;
    while (loop) 
    {
        if (philo[i].stop == 0) 
        {
            time_now = ft_time();
            if (time_now - philo[i].last_meal_time > philo[i].life_limit)
            {
                ft_died(philo, i);
                pthread_mutex_unlock(&philo->print_lock);
                return NULL;
            }
        }
        i++;
        if (i >= philo->nbr_philo || ft_meal_controller(philo) || philo->stop)
            loop = 0;
    }
    return NULL;
}

int ft_meal_controller(t_philosopher *philo)
{
    int i;
    int chk;

    if(philo->meals_allowed_2 > 0 && philo->meals_allowed >= philo->meals_allowed_2)
    {
        i = 0;
        chk = 1;
        while (i < philo->nbr_philo)
        {
			if (philo[i].meals_allowed < philo->meals_allowed_2)
				chk = 0;
            i++;
        }
        while(i < philo->nbr_philo && chk == 1)
        {
            philo[i].stop = 1;
            i++;
        }
        return(1);
    }
    else
        return(0);
}

void *ft_philo_actions(void *arg)
{
    t_philosopher *philo;
    int loop;

    loop = 1;
    philo = (t_philosopher *)arg;
    if (philo->arg->nbr_philo == 1 && !ft_watch_philo(philo))
	{
        loop = 0;
		if (pthread_mutex_lock(philo->left_fork))
			return (NULL);
		printf("has taken a fork");
		while (!ft_meal_controller(philo))
            ;
		pthread_mutex_unlock(philo->left_fork);
	}
	else
		while (loop)
        {
            ft_eat(philo);
            ft_sleep(philo);
            ft_think(philo);
        }
	return (NULL);
}