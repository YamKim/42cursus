#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define number_of_philosophers 2
#define time_to_eat 3000000 
#define US2MS 1000
#define time_to_die 300 
#define time_to_sleep 300 
#define number_of_times_each_philosper_must_eat 3

pthread_t philo[number_of_philosophers];
int	used_fork[number_of_philosophers];
pthread_mutex_t mutexes[number_of_philosophers];

void	take_fork(int fork_num)
{
	pthread_mutex_lock(&mutexes[fork_num]);
	if (used_fork[fork_num] == 0)
	{
		used_fork[fork_num] = 1;
		printf("fork[%d] is used\n", fork_num);
	}
	pthread_mutex_unlock(&mutexes[fork_num]);
}

void	return_fork(int fork_num)
{
	pthread_mutex_lock(&mutexes[fork_num]);
	if (used_fork[fork_num])
	{
		used_fork[fork_num] = 0;
		printf("fork[%d] is returned\n", fork_num);
	}
	pthread_mutex_unlock(&mutexes[fork_num]);
}

void	*set_odd_philo_status(void *arg)
{
	int	philo_num = *(int *)arg;
	int	right_fork_num = philo_num % number_of_philosophers;
	int	left_fork_num = (philo_num + 1) % number_of_philosophers;
	
	take_fork(right_fork_num);
	printf("philo[%d] has taken a right fork\n", philo_num);
	take_fork(left_fork_num);
	printf("philo[%d] has taken a left fork\n", philo_num);

	usleep(time_to_eat);

	return_fork(left_fork_num);
	return_fork(right_fork_num);

	printf("philo[%d] is sleeping\n", philo_num);
	usleep(time_to_sleep);

	return (NULL);
}

void	*set_even_philo_status(void *arg)
{
	int	philo_num = *(int *)arg;
	int	left_fork_num = (philo_num + 1) % number_of_philosophers;
	int	right_fork_num = philo_num % number_of_philosophers;

	take_fork(left_fork_num);
	printf("philo[%d] has taken a left fork\n", philo_num);
	take_fork(right_fork_num);
	printf("philo[%d] has taken a right fork\n", philo_num);

	usleep(time_to_eat);

	return_fork(right_fork_num);
	return_fork(left_fork_num);

	printf("philo[%d] is sleeping\n", philo_num);
	usleep(time_to_sleep);

	return (NULL);
}


int main(void)
{
	pthread_t	pthread[number_of_philosophers];
	int			pthread_ret;
	
	memset(used_fork, 0, number_of_philosophers);

#if 0
	int philo_num = 1;
	pthread_create(&pthread[philo_num], NULL, set_odd_philo_status, (void *)&philo_num);
#endif
#if 1
//	while (1)
//	{
		for(int philo_num = 0; philo_num < number_of_philosophers; ++philo_num)
		{
			if (philo_num % 2 == 0)
			{
				pthread_ret = pthread_create(&pthread[philo_num], NULL, set_even_philo_status, (void *)&philo_num);
				if (pthread_ret)
					return (1);
				pthread_detach(pthread[philo_num]);
			}
			else
				pthread_create(&pthread[philo_num], NULL, set_odd_philo_status, (void *)&philo_num);
		}	
//	}
#endif
	for(int philo_num = 0; philo_num < number_of_philosophers; ++philo_num)
		pthread_join(pthread[philo_num], NULL);
	for(int philo_num = 0; philo_num < number_of_philosophers; ++philo_num)
		pthread_mutex_destroy(&mutexes[philo_num]);
	return (0);
}
