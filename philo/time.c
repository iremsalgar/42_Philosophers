#include "philo.h"

size_t	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	size_t	time;

	time = ft_time();
	usleep(ms * 920);
	while (ft_time() < time + ms) //uyuması için geren süre bitti mi?
		usleep(ms * 3);
}
