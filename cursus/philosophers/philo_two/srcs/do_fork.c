#include "../incs/philo.h"

int
	take_fork(t_info *info, t_philo *philo)
{
	if (sem_wait(info->fork_mutexes))
		return (1);
	show_message(philo, STATUS_FORK);
	if (sem_wait(info->fork_mutexes))
		return (1);
	show_message(philo, STATUS_FORK);
	return (0);
}

int
	return_fork(t_info *info, t_philo *philo)
{
	(void)philo;
	if (sem_post(info->fork_mutexes))
		return (1);
	if (sem_post(info->fork_mutexes))
		return (1);
	return (0);
}
