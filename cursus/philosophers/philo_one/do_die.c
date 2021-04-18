#include "philo.h"

void
	do_die(t_info *info, t_philo *philo)
{
	philo->status = STATUS_DIE;
	show_message(philo, STATUS_DIE);
	info->someone_dead = 1;
}
