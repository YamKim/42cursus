#include "../incs/philo.h"

void
	*run_routine(void *_philo)
{
	t_info		*info;
	t_philo		*philo;

	philo = (t_philo *)_philo;
	info = philo->info;
	while (1)
	{
#if 0
		if (info->someone_dead)
			return (NULL);
#endif
		take_fork(info, philo);
		do_eat(info, philo);
		return_fork(info, philo);
		if (info->finished_thread[philo->pos - 1])
			return (NULL);
#if 0
		if (info->someone_dead)
			return (NULL);
#endif
		do_sleep(info, philo);
	}
	return (NULL);
}
