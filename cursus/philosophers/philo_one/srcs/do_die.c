#include "../incs/philo.h"

void
	do_die(t_info *info, t_philo *philo)
{
	show_message(philo, STATUS_DIE);
	pthread_mutex_unlock(&(info->someone_dead_mutex));
}
