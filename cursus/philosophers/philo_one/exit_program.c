#include "philo.h"

int
	exit_program(t_info *info)
{
	int		idx;
	t_philo	*philo;

	if (info->fork_mutexes)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
			pthread_mutex_destroy(&(info->fork_mutexes[idx]));
		free(info->fork_mutexes);
	}
	if (info->philos)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
		{
			philo = &(info->philos[idx]);
			pthread_mutex_destroy(&(philo->mutex));
		}
		free(info->philos);
	}
	free(info->philos);
	return (1);
}
