#include "philo.h"

void
	take_fork(t_info *info, t_philo *philo)
{
	int	lfork;
	int	rfork;

	lfork = philo->lfork;
	rfork = philo->rfork;
	pthread_mutex_lock(&(info->fork_mutexes[lfork]));
	printf("taken: lfork[%d]\n", lfork); 
	show_message(philo, STATUS_FORK);
	pthread_mutex_lock(&(info->fork_mutexes[rfork]));
	printf("taken: rfork[%d]\n", rfork); 
	show_message(philo, STATUS_FORK);
}

void
	return_fork(t_info *info, t_philo *philo)
{
	int	lfork;
	int	rfork;

	lfork = philo->lfork;
	rfork = philo->rfork;
	printf("returned: lfork[%d]\n", lfork); 
	pthread_mutex_unlock(&(info->fork_mutexes[lfork]));
	printf("returned: rfork[%d]\n", rfork); 
	pthread_mutex_unlock(&(info->fork_mutexes[rfork]));
}

void
	run_eat(t_info *info, t_philo *philo)
{
	philo->is_eating = 1;
	show_message(philo, STATUS_EAT);
	usleep(info->time_to_eat * MSEC2USEC);
	philo->is_eating = 0;
}

void
	run_sleep(t_info *info, t_philo *philo)
{
	show_message(philo, STATUS_SLEEP);
	usleep(info->time_to_sleep * MSEC2USEC);
}

void
	*run_routine(void *philo)
{
	t_info	*info;

	info = ((t_philo *)philo)->info;
	while (1)
	{
		printf("philo[%d] is ready to eat\n", ((t_philo *)philo)->pos);
		take_fork(info, philo);
		run_eat(info, philo);	
		return_fork(info, philo);
		run_sleep(info, philo);
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
	while (++idx < info->num_of_philos)
	{
		philo = (void *)(&info->philos[idx]);
		if (pthread_create(&tid, NULL, &run_routine, philo))
			return (1);
		pthread_detach(tid);
	}
	return (0);
}

int
	main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info, argc, argv);
	printf("info->num_of_philos: %d, time_to_die: %lld, time_to_eat: %lld, time_to_sleep: %lld\n",\
			info.num_of_philos, info.time_to_die, info.time_to_eat, info.time_to_sleep);
	init_threads(&info);

	while(1)
	{
	;
	}

	free(info.philos);
	return (0);
}
