#include "philo.h"

uint64_t
	get_cur_time()
{
	struct timeval	tmp;
	uint64_t		ret;

	if (gettimeofday(&tmp, NULL) == -1)
		return (-1);
	ret = tmp.tv_sec * SEC2USEC + tmp.tv_usec * USEC2MSEC;
	return (ret);
}
