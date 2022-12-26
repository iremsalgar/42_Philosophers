#include "philo.h"

int ft_init_arg(t_arg *arg, int ac, char **av)
{
    arg->nbr_philo = ft_atoi(av[1]);
    arg->time_to_die = ft_atoi(av[2]);
    arg->time_to_eat = ft_atoi(av[3]);
    arg->time_to_sleep = ft_atoi(av[4]);
    arg->dead = 0;
    if(ac == 6)
        arg->nbr_of_meal = ft_atoi(av[5]);
    if(ac == 5)
        arg->nbr_of_meal = -1;
    if(ac == 5 && arg->nbr_philo < 1)
        return(0);
    if(ac == 6 && arg->nbr_of_meal < 1)
        return(0);
    return(0);
}

void ft_init_mutex(t_arg *arg)
{
    int             philo_number;
    pthread_mutex_t *mutex;

    philo_number = arg->nbr_philo;
    mutex = malloc(sizeof(pthread_mutex_t) * philo_number);
    while(philo_number-- > 0)
        pthread_mutex_init(&mutex[philo_number], NULL);
    pthread_mutex_init(&arg->print_lock, NULL);
    arg->fork = mutex;
}

void ft_init_philosophers(t_arg *arg)
{
    int i;
    t_philosopher   *philo;

    i = 0;
    philo = calloc(sizeof(t_philosopher), arg->nbr_philo);
    while(i < arg->nbr_philo)
    {
        philo[i].id = i;
        philo[i].time_to_die = arg->time_to_die;
        philo[i].time_to_eat = arg->time_to_eat;
        philo[i].time_to_sleep = arg->time_to_sleep;
        philo[i].last_meal_time = 0;
        philo[i].nbr_philo = arg->nbr_philo;
        philo[i].stop = 0;
        philo[i].meals_allowed = 0;
        philo[i].meals_allowed_2 = arg->nbr_of_meal;
        philo[i].life_limit = arg->time_to_die;
        philo[i].left_fork = &arg->fork[philo[i].id];
        philo[i].right_fork = &arg->fork[(philo[i].id + 1) % arg->nbr_philo];
        philo[i].arg = arg;
        i++;
    }
    arg->all_philo = philo;
}

void ft_init_threads(t_arg *arg, t_philosopher *philo)
{
    int p_nbr;
    pthread_t   *threads;

    p_nbr = arg->nbr_philo;
    threads = malloc(sizeof(pthread_t) * p_nbr);
    while(p_nbr--)
        pthread_create(&threads[p_nbr], NULL, ft_philo_actions, (void *)&philo);
    p_nbr = arg->nbr_philo;
    while(p_nbr--)
        pthread_join(threads[p_nbr], NULL);
    arg->all_thread = threads;
}