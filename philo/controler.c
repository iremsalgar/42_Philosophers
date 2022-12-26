#include "philo.h"

int	ft_is_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
		else
			return (0);
	}
	if (res >= __INT_MAX__)
		return (0);
	return (res);
}

int ft_ac_av_controller(char **av)
{
    size_t i;

	i = 1;
    while(av[i])
    {
        if(!(ft_is_digit(av[i])) || !(ft_atoi(av[i])))
        {
            printf("\x1b[31m wrong argument kido\x1b[0m \n");
            return(1);
        }
        i++;
    }
    return(0);
}