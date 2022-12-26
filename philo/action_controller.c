#include "philo.h"

void *ft_watch_philo(void *arg)
{
    t_philosopher *philo;
    long time_now;
    int i;
    int loop;

    philo = (t_philo *)args;
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
                pthread_mutex_unlock(&philo->lock_print);
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
    t_philosopher = *philo;

    philo = (t_philo *)arg;
    philo->last_meal_time = ft_time();
    philo->start_time = ft_time();
    while(!philo->arg->dead) //1
    {
        if (philo->arg->dead || philo->stop || ft_meal_controller(philo))
			return (NULL);
		ft_take_fork(philo);
		if (philo->arg->dead || philo->stop || ft_meal_controller(philo))
			return (NULL);
		ft_eat(philo);
		if (philo->arg->dead || philo->stop || ft_meal_controller(philo))
			return (NULL);
		ft_sleep(philo);
		if (philo->arg->dead || philo->stop || ft_meal_controller(philo))
			return (NULL);
		ft_think(philo);
		if (philo->arg->dead || philo->stop || ft_meal_controller(philo))
			return (NULL);
    }
    return(NULL);
}