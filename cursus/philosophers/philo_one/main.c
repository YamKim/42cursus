#include "philo.h"

void
	*observe_must_eat_arr(void *_info)
{
	int		idx;
	t_info	*info;
	
	info = (t_info *)_info;
	while (1)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
		{
			// TODO: solve the segment fault problem
			// TODO: when somebody is died! do need mutex?
			if (!(info->eat_cnt_arr[idx]))
				break ;
		}
		if (idx == info->num_of_philos)
			return(exit_threads(info));
	}
	return (NULL);
}

int
	init_threads(t_info *info)
{
	int			idx;
	void		*philo;
	pthread_t	tid;

	idx = -1;
	info->beg_prog_time = get_cur_time();
	if (info->num_of_must_eat > 0)
	{
		if (pthread_create(&tid, NULL, &observe_must_eat_arr, info))
			return (ERR_INIT_THREAD);
		pthread_detach(tid);
	}
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
	init_threads(&info);
#if 1
	while (1)
	{
	;
	}
#endif

	exit_program(&info);
	return (0);
}
