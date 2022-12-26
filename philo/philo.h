#ifndef PHILO_H
# define PHILO_H

#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

typedef struct s_arg
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
    int             nbr_of_meals;
    pthread_mutex_t print_lock;
    pthread_mutex_t *fork;
    t_philo			*all_philo;
    pthread_t       *all_thread;
}   t_arg;

typedef struct s_philosopher
{
    int             id;               // filozofun kimliği
    int             nbr_philo;
    int             meals_eaten;      // filozofun yediği yemek sayısı
    int             meals_allowed;    // filozofun yemesi için izin verilen toplam yemek sayısı
    int             meals_allowed_2;
    int             time_to_eat;      // filozofun bir yemek yemesi için gereken süre
    int             time_to_sleep;    // filozofun uyuması için gereken süre
    int             time_to_die;      // filozofun ölmesi için gereken süre
    int             last_meal_time;   // filozofun son yediği yemeğin zamanı
    int             life_limit;
    int             stop;
    int             start_time;
    pthread_mutex_t *left_fork;  // filozofun sol çatalı
    pthread_mutex_t *right_fork; // filozofun sağ çatalı
    struct s_arg	*arg;
}   t_philosopher;

int     main(int ac, char **av);
int     ft_ac_av_controller(char **av);
int     ft_atoi(const char *str);
int     ft_is_digit(char *str);
int     ft_init_arg(t_arg *arg, int ac, char **av);
int     ft_init_mutex(t_arg *arg);
int     ft_init_philosophers(t_arg *arg);
int     ft_init_threads(t_arg *arg);
long    ft_time(void);
void    *ft_philo_actions(void *arg);
int     ft_meal_controller(t_philosopher *philo);
void    *ft_watch_philo(void *arg);

#endif