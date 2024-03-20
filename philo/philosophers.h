/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:21:14 by antferna          #+#    #+#             */
/*   Updated: 2024/03/20 12:29:07 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# define PHIL_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;
typedef struct s_data
{
	int				i;
	int				dead_flag;
	int				num_of_philos;
	int				num_times_to_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	forks[PHIL_MAX];
	t_philo			philos[PHIL_MAX];
}					t_data;

/*---- PHILO_UTILS.C ----*/
long long int	ft_atol(const char *str);
int				ft_usleep(size_t milliseconds);
size_t			get_current_time(void);
int				check_args(char **argv);

/*---- THREADS.C ----*/
void			philo_msg(char *s, t_data *d);
int				start_threads(t_data *d);

#endif