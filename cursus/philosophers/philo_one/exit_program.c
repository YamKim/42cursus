#include "philo.h"

void
	*exit_threads(t_info *info)
{
	int		idx;
	t_philo	*philo;

	if (info->fork_mutexes)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
			pthread_mutex_destroy(&(info->fork_mutexes[idx]));
	}
	if (info->philos)
	{
		idx = -1;
		while (++idx < info->num_of_philos)
		{
			philo = &(info->philos[idx]);
			pthread_mutex_destroy(&(philo->mutex));
		}
	}
	return (NULL);
}

void
	exit_program(t_info *info)
{
	if (info->fork_mutexes != NULL)
	{
		free(info->fork_mutexes);
		info->fork_mutexes = NULL;
	}
	if (info->philos != NULL)
	{
		free(info->philos);
		info->philos = NULL;
	}
}
