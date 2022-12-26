#ifndef PHILO_H
# define PHILO_H

#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

struct s_philosopher;

typedef struct s_arg
{
	int				    nbr_philo;
    int                 dead;
	int				    time_to_die;
	int				    time_to_eat;
	int				    time_to_sleep;
    int                 nbr_of_meal;
    pthread_mutex_t         print_lock;
    pthread_mutex_t         *fork;
    struct s_philosopher    *all_philo;
    pthread_t           *all_thread;
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
    time_t          last_meal_time;   // filozofun son yediği yemeğin zamanı
    time_t          life_limit;
    int             stop;
    time_t          start_time;
    pthread_mutex_t *left_fork;  // filozofun sol çatalı
    pthread_mutex_t *right_fork; // filozofun sağ çatalı
    pthread_mutex_t print_lock;
    struct s_arg	*arg;
}   t_philosopher;

int     main(int ac, char **av);
int     ft_ac_av_controller(char **av);
int     ft_atoi(const char *str);
int     ft_is_digit(char *str);
int     ft_init_arg(t_arg *arg, int ac, char **av);
void    ft_init_mutex(t_arg *arg);
void    ft_init_philosophers(t_arg *arg);
void     ft_init_threads(t_arg *arg);
long    ft_time(void);
void    *ft_philo_actions(void *arg);
int     ft_meal_controller(t_philosopher *philo);
void    *ft_watch_philo(void *arg);
void	ft_take_fork(t_philosopher *philo);
void	ft_eat(t_philosopher *philo);
void	ft_usleep(int ms);
void	ft_sleep(t_philosopher *philo);
void	ft_think(t_philosopher *philo);
void	ft_died(t_philosopher *philo, int i);
void	ft_finish_thread(t_arg *arg);
void	ft_unlock_and_destroy_mutex(t_arg *arg);
void	ft_free_all(t_arg *arg);

#endif