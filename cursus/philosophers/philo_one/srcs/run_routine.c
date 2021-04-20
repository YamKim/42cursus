#include "../incs/philo.h"

void
	*exit_philo_thread(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->mutex));
	return (NULL);
}

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
			return (exit_philo_thread(philo));
		take_fork(info, philo);
		do_eat(info, philo);
		return_fork(info, philo);
		if (info->finished_thread[philo->pos - 1])
			return (exit_philo_thread(philo));
		do_sleep(info, philo);
	}
	return (NULL);
}
