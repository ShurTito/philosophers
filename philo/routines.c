/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:42:00 by antferna          #+#    #+#             */
/*   Updated: 2024/03/27 12:47:17 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *p)
{
	philo_msg("is thinking", p);
}

void	dreaming(t_philo *p)
{
	philo_msg("is sleeping", p);
	ft_usleep(p->time_to_sleep);
}

void	eating(t_philo *p)
{
	pthread_mutex_lock(p->r_fork);
	philo_msg("has taken a fork", p);
	if (p->data->num_of_philos == 1)
	{
		ft_usleep(p->time_to_die);
		pthread_mutex_unlock(p->r_fork);
		return ;
	}
	pthread_mutex_lock(p->l_fork);
	philo_msg("has taken a fork", p);
	philo_msg("is eating", p);
	pthread_mutex_lock(&p->data->meal_lock);
	p->last_meal = get_current_time();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->data->meal_lock);
	ft_usleep(p->time_to_eat);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
}
