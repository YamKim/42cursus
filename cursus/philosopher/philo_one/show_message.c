#include "philo.h"
void
	show_message(t_philo *philo, int status)
{
	char	*status_str;

	if (status == STATUS_FORK)
		status_str = "has taken a fork";
	else if  (status == STATUS_EAT)
		status_str = "is eating";
	else if  (status == STATUS_SLEEP)
		status_str = "is sleeping";
	printf("%d %s\n", philo->pos, status_str);
}

