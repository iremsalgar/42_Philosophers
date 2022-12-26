#include "philo.h"

int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        if(ft_ac_av_controller(av))
            return(1);
        if(ft_init_arg(&arg, argc, argv))
            return(1);
        ft_init_mutex(&arg);
        ft_init_philosophers(&arg);
        ft_init_threads(&arg);
    }
}