#include "../incs/philo.h"

#if 0
static int
	is_all_philos_eat_must(t_info *info)
{
	int	idx;

	idx = -1;
	while (++idx < info->num_of_philos)
	{
		if (!(info->finished_thread[idx]))
			break ;
	}
	if (idx == info->num_of_philos)
		return(1);
	return (0);
}
#endif

#if 0
static void
	*do_observe_philos_status(void *_info)
{
	t_info		*info;
	t_philo		*philo;
	int			idx;
	uint64_t	dif_time;

	info = (t_info *)_info;
	while(1)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
		{
			philo = &(info->philos[idx]);
			dif_time = get_cur_time() - philo->beg_eat_time;
			if (!(philo->status == STATUS_EAT) \
					&& dif_time > info->time_to_die)
			{
				do_die(info, philo);
				return (NULL);
			}
		}
	}
	return (NULL);
}
#endif

int
	run_threads(t_info *info)
{
	int			idx;
	void		*philo;
	pthread_t	tid;

	idx = -1;
	info->beg_prog_time = get_cur_time();
#if 0
	if (pthread_create(&tid, NULL, &do_observe_philos_status, info))
		return (ERR_INIT_THREAD);
	pthread_detach(tid);
#endif
	while (++idx < info->num_of_philos)
	{
		philo = (void *)(&info->philos[idx]);
		if (pthread_create(&tid, NULL, &run_routine, philo))
			return (ERR_INIT_THREAD);
		pthread_detach(tid);
		usleep(100);
	}
	return (0);
}

int
	main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info, argc, argv);
	run_threads(&info);
	while (1)
	{
		if (info.someone_dead)
		{
			break ;
		}
#if 0
		if (is_all_philos_eat_must(&info))
			break ;
		pthread_mutex_unlock(&info.mutex);
		usleep(10 * USEC2MSEC);
#endif
	}
	destroy_mutexes(&info);
	//free_memory(&info);
	return (0);
}
