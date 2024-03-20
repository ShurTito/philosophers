/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antferna <antferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:42:00 by antferna          #+#    #+#             */
/*   Updated: 2024/03/20 12:42:14 by antferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_data *d)
{
	philo_msg("is thinking", d);
}

void	dream(t_data *d)
{
	philo_msg("is sleeping", d);
	ft_usleep(d->philos[d->i].time_to_sleep);
}