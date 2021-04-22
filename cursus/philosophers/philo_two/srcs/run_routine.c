#include "../incs/philo.h"

#if 1
static void
	*observe_philo_status(void *_philo)
{
	t_philo		*philo;
	t_info		*info;
	uint64_t	dif_time;

	philo = (t_philo *)_philo;
	info = philo->info;
	while(1)
	{
		if (info->someone_dead)
			return (NULL);
		if (sem_wait(philo->mutex))
			return (NULL);
		dif_time = get_cur_time() - philo->beg_eat_time;
		if (!(philo->status == STATUS_EAT) \
				&& dif_time > info->time_to_die)
		{
			do_die(info, philo);
			return (NULL);
		}
		if (sem_post(philo->mutex))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
#endif

void
	*run_routine(void *_philo)
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)_philo;
	info = philo->info;
#if 1
	if (pthread_create(&tid, NULL, &observe_philo_status, philo))
		return (NULL);
	pthread_detach(tid);
#endif
	while (1)
	{
		if (info->someone_dead)
			return (NULL);
		if (take_fork(info, philo))
			return (NULL);
		if (do_eat(info, philo))
			return (NULL);
		if (return_fork(info, philo))
			return (NULL);
		if (info->finished_thread[philo->pos - 1])
			return (NULL);
		if (info->someone_dead)
			return (NULL);
		if (do_sleep(info, philo))
			return (NULL);
	}
	return (NULL);
}