#include "philo.h"

void	ft_finish_thread(t_arg *args)
{
	int	p_nbr;

	p_nbr = args->nbr_philo;
	if (p_nbr == 1)
		pthread_mutex_unlock(&args->fork[0]);
	while (p_nbr)
	{
	    p_nbr--;
		pthread_join(args->all_thread[p_nbr], NULL);
	}
}
//nbr_ph 1'e eşitse, işlev, 
//t_arg yapısındaki forks dizisinin ilk dizinindeki muteksin kilidini açar.


//Ardından işlev, nbr_ph 0 olana kadar çalışan bir döngüye girer. 
//Döngü içinde, nbr_ph değerini 1 azaltır ve ardından pthread_join işlevini çağırarak, 
//nbr_ph dizininde tids dizisinde saklanan iş parçacığı kimliğini ve 
//argüman olarak bir NULL değerini iletir. . 
//Bu, çağıran iş parçacığının, belirtilen kimliğe sahip 
//iş parçacığı yürütmeyi bitirene kadar bloke olmasına neden olur.