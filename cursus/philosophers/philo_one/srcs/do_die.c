#include "../incs/philo.h"

void
	do_die(t_info *info, t_philo *philo)
{
	int	idx;

	show_message(philo, STATUS_DIE);
	pthread_mutex_lock(&(info->msg_mutex));
	pthread_mutex_unlock(&(info->someone_dead_mutex));
	idx = -1;
#if 1
	while (++idx < info->num_of_philos)
		pthread_mutex_unlock(&info->philos[idx].eat_mutex);
#endif
}
