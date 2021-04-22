#include "../incs/philo.h"

void
	do_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex));
	philo->status = STATUS_EAT;
	philo->beg_eat_time = get_cur_time();
	show_message(philo, STATUS_EAT);
	usleep(info->time_to_eat * MSEC2USEC);
	++(philo->eat_cnt);
#if 1
	if (philo->eat_cnt == info->num_of_must_eat)
	{
		philo->eat_finished = 1;
		pthread_mutex_unlock(&(philo->eat_mutex));
	}
#endif
	pthread_mutex_unlock(&(philo->mutex));
}