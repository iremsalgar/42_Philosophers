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
	int	i;

	res = 0;
	i = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * i);
}

int ft_ac_av_controller(char **av)
{
    size_t i;

    while(av[i])
    {
        if(!ft_is_digit(argv[i]) || (!ft_atoi(av[i])))
        {
            printf("wrong argument kido\n");
            return(1);
        }
        i++;
    }
    return(0);
}