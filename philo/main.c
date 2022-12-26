#include "philo.h"

static void ft_check_arg(void)
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

int main(int ac, char **av)
{
    t_arg   arg;

    if(ac == 5 || ac == 6)
    {
        if(ft_ac_av_controller(av))
            return(1);
        if(ft_init_arg(&arg, ac, av))
            return(1);
        ft_init_mutex(&arg);
        ft_init_philosophers(&arg);
        ft_init_threads(&arg, arg.all_philo);
        ft_finish_thread(&arg);
        ft_unlock_and_destroy_mutex(&arg);
	    ft_free_all(&arg);
    }
    else if(ac < 5 || ac > 6)
    {
        ft_check_arg();
        return(1);
    }
    return(0);
}