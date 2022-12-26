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

/*
Bu fonksiyon, verilen t_arg tipindeki argüman içerisinde 
belirtilen filozoflar için oluşturulmuş olan iş parçacıklarını (threads) sonlandırır. 
Öncelikle, eğer sadece bir filozof varsa, bu filozofun eline verilen bir çatalın kilidini açar. 
Daha sonra, nbr_philo adlı değişkenin değerine eşit olan kadar döngü yapılır ve 
bu döngüler içerisinde, all_thread dizisinden çekilen her bir iş parçacığına pthread_join fonksiyonu ile katılınır. 
Bu işlev, belirtilen iş parçacığı sona erene kadar çağıran iş parçacığını engeller.
Bu sayede, iş parçacıkları sonlandırılmış olur.
*/
//nbr_ph 1'e eşitse, işlev, 
//t_arg yapısındaki forks dizisinin ilk dizinindeki muteksin kilidini açar.

//nbr_ph 0 olana kadar çalışan bir döngüye girer. 
//Döngü içinde, nbr_ph değerini 1 azaltır ve ardından pthread_join işlevini çağırarak, 
//nbr_ph dizininde tids dizisinde saklanan iş parçacığı kimliğini ve 
//argüman olarak bir NULL değerini iletir. . 
//Bu, çağıran iş parçacığının, belirtilen kimliğe sahip 
//iş parçacığı yürütmeyi bitirene kadar bloke olmasına neden olur.


void	ft_free_all(t_arg *arg)
{
	free(arg->all_thread);
	free(arg->all_philos);
	free(arg->forks);
}

void	ft_unlock_and_destroy_mutex(t_arg *arg)
{
	int	p_nbr;

	p_nbr = arg->nbr_philo;
	while (p_nbr--)
	{
		pthread_mutex_unlock(&arg->fork[p_nbr]);
		pthread_mutex_destroy(&arg->fork[p_nbr]);
	}
	pthread_mutex_unlock(&(*arg).lock_print);
	pthread_mutex_destroy(&(*arg).lock_print);
}