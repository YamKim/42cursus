#include "../incs/philo.h"

int
	do_die(t_info *info, t_philo *philo)
{
	if (sem_post(info->someone_dead_mutex))
		return (ERR_SEM_DO);
	show_message(philo, STATUS_DIE);
	if (sem_wait(info->msg_mutex) != 0)
		return (ERR_SEM_DO);
	return (0);
}
