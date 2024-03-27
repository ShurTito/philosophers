/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:23:39 by antferna          #+#    #+#             */
/*   Updated: 2024/03/27 12:47:48 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	init_forks_philos(t_data *data, t_philo *philos, char **argv)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = -1;
	while (++i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_current_time();
		philos[i].time_to_die = ft_atol(argv[2]);
		philos[i].time_to_eat = ft_atol(argv[3]);
		philos[i].time_to_sleep = ft_atol(argv[4]);
		philos[i].start_time = get_current_time();
		philos[i].l_fork = &data->forks[i];
		if (i == 0)
			philos[i].r_fork = &data->forks[data->num_of_philos - 1];
		else
			philos[i].r_fork = &data->forks[i - 1];
		philos[i].data = data;
	}
}

static void	init_program(t_data *data, t_philo *philos, char **argv, int argc)
{
	data->i = 0;
	data->dead_flag = 0;
	data->num_of_philos = ft_atol(argv[1]);
	data->num_times_to_eat = -1;
	if (argc == 6)
		data->num_times_to_eat = ft_atol(argv[5]);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	init_forks_philos(data, philos, argv);
}

int	main(int argc, char **argv)
{
	t_data				data;
	t_philo				philos[PHIL_MAX];

	if (!check_args(argv) || argc < 5 || argc > 6)
		return (printf("Invalid Arguments\n"), 1);
	init_program(&data, philos, argv, argc);
	start_threads(philos);
	destroy_mutex(philos);
}
