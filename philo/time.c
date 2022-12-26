#include "philo.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			result;

	gettimeofday(&tv, NULL);
	result = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (result);
}

void	ft_usleep(int ms)
{
	long	time;

	time = ft_time();
	usleep(ms * 920);
	while (ft_time() < time + ms) //uyuması için geren süre bitti mi?
		usleep(ms * 3);
}
