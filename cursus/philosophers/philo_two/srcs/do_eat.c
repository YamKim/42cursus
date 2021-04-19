#include "../incs/philo.h"

int
	do_eat(t_info *info, t_philo *philo)
{
	if (sem_wait(philo->mutex))
		return (1);
	philo->status = STATUS_EAT;
	philo->beg_eat_time = get_cur_time();
	show_message(philo, STATUS_EAT);
	usleep(info->time_to_eat * MSEC2USEC);
	++(philo->eat_cnt);
#if 0
	if (philo->eat_cnt == info->num_of_must_eat)
		info->finished_thread[philo->pos - 1] = 1;
#endif
#if 0
	if (philo->eat_cnt == info->num_of_must_eat)
		philo->eat_finish = 1;
#endif
	if (sem_post(philo->mutex))
		return (1);
	return (0);
}
