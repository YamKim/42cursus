#ifndef _PHILO_H
# define _PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define STATUS_EAT 0
# define STATUS_SLEEP 1
# define STATUS_FORK 2
# define STATUS_THINK 3

# define SEC2USEC 1000
# define MSEC2USEC 1000
# define USEC2MSEC 1/1000


typedef struct	s_status
{


}				t_status;

typedef	struct	s_info
{
	uint64_t	beg_time;
	uint64_t	cur_time;
	int			num_of_philos;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			which_thread;
	pthread_mutex_t \
				*fork_mutexes;
	struct s_philo	\
				*philos;
}				t_info;

typedef struct	s_philo
{
	int			pos;
	int			is_eating;
	uint64_t	limit;
	uint64_t	last_eat_start;
	int			lfork;
	int			rfork;
	t_info		*info;
	t_status	*status;
}				t_philo;

/*
** init_info.c
*/
int
	init_info(
	t_info *info,
	int argc,
	char *argv[]);

/*
** ft_utils.c
*/
int
	ft_atoi(const char *nptr);
void
	ft_putnbr_fd(int n, int fd);

/*
** show_message.c
*/
void
	show_message(t_philo *philo, int status);

/*
** get_cur_time.c
*/
uint64_t
	get_cur_time();


#endif
