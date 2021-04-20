#include "../incs/philo.h"

void
	do_sleep(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->status = STATUS_SLEEP;
	show_message(philo, STATUS_SLEEP);
	usleep(info->time_to_sleep * MSEC2USEC);
	pthread_mutex_unlock(&philo->mutex);
}
