#include "../incs/philo.h"

void
	*exit_threads(t_info *info)
{
	int		idx;

	if (info->fork_mutexes)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
			pthread_mutex_destroy(&(info->fork_mutexes[idx]));
	}
	pthread_mutex_destroy(&(info->mutex));
	return (NULL);
}

