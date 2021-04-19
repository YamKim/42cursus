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
		if (info->someone_dead)
			return (NULL);
		if (take_fork(info, philo))
			return (NULL);
		if (do_eat(info, philo))
			return (NULL);
		if (return_fork(info, philo))
			return (NULL);
		if (philo->eat_finish)
		{
			info->finished_thread[philo->pos - 1] = 1;
			break ;
		}
		if (info->someone_dead)
			return (NULL);
		if (do_sleep(info, philo))
			return (NULL);
	}
	return (NULL);
}
