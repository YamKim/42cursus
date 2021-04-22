#include "../incs/philo.h"

int
	do_die(t_info *info, t_philo *philo)
{
	show_message(philo, STATUS_DIE);
	info->someone_dead = 1;
	return (0);
}
