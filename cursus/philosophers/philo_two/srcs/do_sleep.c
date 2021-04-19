#include "../incs/philo.h"

int
	do_sleep(t_info *info, t_philo *philo)
{
	if (sem_wait(philo->mutex) != 0)
		return (1);
	philo->status = STATUS_SLEEP;
	show_message(philo, STATUS_SLEEP);
	usleep(info->time_to_sleep * MSEC2USEC);
	if (sem_post(philo->mutex))
		return (1);
	return (0);
}
