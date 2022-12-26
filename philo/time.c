#include "philo.h"

long ft_time(void)
{
    struct timeval	tv;
	long			result;

	gettimeofday(&tv, NULL);
	result = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (result);
}