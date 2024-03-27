/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:06:42 by antferna          #+#    #+#             */
/*   Updated: 2024/03/27 12:47:41 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	feed_all_check(t_philo *p)
{
	int	i;
	int	feed;

	if (p->data->num_times_to_eat == -1)
		return (0);
	i = -1;
	feed = 0;
	while (++i < p->data->num_of_philos)
	{
		pthread_mutex_lock(&p->data->meal_lock);
		if (p[i].meals_eaten >= p->data->num_times_to_eat)
			feed++;
		pthread_mutex_unlock(&p->data->meal_lock);
	}
	if (feed == p->data->num_of_philos)
	{
		pthread_mutex_lock(&p->data->dead_lock);
		p->data->dead_flag = 1;
		pthread_mutex_unlock(&p->data->dead_lock);
		return (1);
	}
	return (0);
}

int	philo_dead(t_philo *philo, size_t time_to_die, t_philo *p)
{
	pthread_mutex_lock(&p->data->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die)
		return (pthread_mutex_unlock(&p->data->meal_lock), 1);
	pthread_mutex_unlock(&p->data->meal_lock);
	return (0);
}

int	dead_check(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->num_of_philos)
	{
		if (philo_dead(&p[i], p[i].time_to_die, p))
		{
			philo_msg("died", p);
			pthread_mutex_lock(&p->data->dead_lock);
			p->data->dead_flag = 1;
			pthread_mutex_unlock(&p->data->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (69)
	{
		if (feed_all_check(p) || dead_check(p))
			break ;
	}
	return (philo);
}
