#include "philo.h"

void
	do_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = STATUS_EAT;
	philo->beg_eat_time = get_cur_time();
	show_message(philo, STATUS_EAT);
	usleep(info->time_to_eat * MSEC2USEC);
	++(philo->eat_cnt);
#if 0
	if (philo->eat_cnt == info->num_of_must_eat)
		info->eat_cnt_arr[philo->pos - 1] = 1;
#endif
	if (philo->eat_cnt == info->num_of_must_eat)
		philo->eat_finish = 1;
	pthread_mutex_unlock(&philo->mutex);
}
