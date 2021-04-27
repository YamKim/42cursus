#include "../incs/philo.h"

int
	do_die(t_info *info, t_philo *philo)
{
	int	idx;

	if (info->program_finished)
		return (0);
	show_message(philo, STATUS_DIE);
	if (sem_post(info->someone_dead_mutex))
		return (ERR_SEM_DO);
	info->program_finished = 1;
	idx = -1;
#if 1
	while (++idx < info->num_of_philos)
	{
		if (info->philos[idx].eat_finished)
			continue ;
		if (sem_post(info->philos[idx].eat_mutex))
			return (ERR_SEM_DO);
	}
#endif
	return (0);
}
