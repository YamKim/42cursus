#include "philo.h"

static void
	*do_observe(void *_philo)
{
	t_philo		*philo;
	uint64_t	dif_time;
	uint64_t	lim_time;

	philo = (t_philo *)_philo;
	while(1)
	{
		pthread_mutex_lock(&philo->mutex);
		dif_time = get_cur_time() - philo->beg_eat_time;
		lim_time = philo->info->time_to_die;
		if (!(philo->status == STATUS_EAT) && dif_time > lim_time)
		{
			// TODO: solve the segment fault problem
			// TODO: when somebody is died! do need mutex?
			show_message(philo, STATUS_DIE);
#if 0
			printf("pos: %d\n", philo->pos);
			printf("eat_cnt: %d\n", philo->eat_cnt);
			printf("eat_cnt_arr[]: %d\n", philo->info->eat_cnt_arr[philo->pos - 1]);
#endif
			return(exit_threads(philo->info));
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(10 * USEC2MSEC);
	}
	return (NULL);
}

void
	*run_routine(void *philo)
{
	t_info		*info;
	t_philo		*observer;
	pthread_t	tid;

	info = ((t_philo *)philo)->info;
	observer = (t_philo *)philo;
	if (pthread_create(&tid, NULL, &do_observe, observer))
		return (NULL);
	pthread_detach(tid);
	while (1)
	{
		take_fork(info, philo);
		do_eat(info, philo);
		return_fork(info, philo);
		do_sleep(info, philo);
	}
	return (NULL);
}
