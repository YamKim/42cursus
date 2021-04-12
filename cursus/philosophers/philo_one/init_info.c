#include "philo.h"

static int
	init_mutexes(t_info *info)
{
	int		size;
	int		idx;

	size = sizeof(pthread_mutex_t) * info->num_of_philos;
	info->fork_mutexes = (pthread_mutex_t *)malloc(size);
	if (!info->fork_mutexes)
		return (1);
	idx = -1;
	while (++idx < info->num_of_philos)
		pthread_mutex_init(&(info->fork_mutexes[idx]), NULL);
	return (0);
}

static void
	init_philos(t_info *info)
{
	int		itr;

	itr = -1;
	while (++itr < info->num_of_philos)
	{
		info->philos[itr].is_eating = 0;
		info->philos[itr].pos = itr + 1;
		info->philos[itr].lfork = itr;
		info->philos[itr].rfork = (itr + 1) % info->num_of_philos;
		info->philos[itr].info = info;
	}
}

int
	init_info(
	t_info *info,
	int argc,
	char *argv[])
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);

	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philos);
	if (!info->philos)
		return (1);
	init_philos(info);
	
	return (init_mutexes(info) );
}
