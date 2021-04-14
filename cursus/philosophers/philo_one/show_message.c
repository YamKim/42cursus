#include "philo.h"

void
	show_message(t_philo *philo, int status)
{
	char		*status_str;
	t_info		*info;
	uint64_t	dif_time;

	info = philo->info;
	if (status == STATUS_FORK)
		status_str = "has taken a fork";
	else if  (status == STATUS_EAT)
		status_str = "is eating";
	else if  (status == STATUS_SLEEP)
		status_str = "is sleeping";
	dif_time = get_cur_time() - info->beg_prog_time;
	printf("%lld %d %s\n", dif_time, philo->pos, status_str);
}
