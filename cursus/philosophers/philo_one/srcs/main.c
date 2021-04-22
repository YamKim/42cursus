#include "../incs/philo.h"

int
	is_all_thread_finished(t_info *info)
{
	int	idx;

	idx = -1;
	while (++idx < info->num_of_philos)
	{
		if (!(info->finished_thread[idx]))
			return (0);
	}

	return (1);
}

int
	run_threads(t_info *info)
{
	int			idx;
	void		*philo;
	pthread_t	tid;

	idx = -1;
	info->beg_prog_time = get_cur_time();
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
#if 0
	while (1)
	{
		if (is_all_thread_finished(&info))
			break ;
		if (info.someone_dead)
			break ;
	}
#endif
	
	pthread_mutex_lock(&(info.someone_dead_mutex));
	pthread_mutex_unlock(&(info.someone_dead_mutex));
	usleep(10000);
	destroy_mutexes(&info);
	free_memory(&info);
	return (0);
}
