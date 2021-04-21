#include "../incs/philo.h"

void
	*destroy_mutexes(t_info *info)
{
	int		idx;

	if (info->fork_mutexes)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
		{
			pthread_mutex_destroy(&(info->fork_mutexes[idx]));
			pthread_mutex_destroy(&(info->philos[idx].mutex));
		}
	}
	pthread_mutex_destroy(&(info->msg_mutex));
	return (NULL);
}

