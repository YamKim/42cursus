#include "philo.h"

void
	do_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->beg_eat_time = get_cur_time();
	show_message(philo, STATUS_EAT);
	usleep(info->time_to_eat * MSEC2USEC);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
}

