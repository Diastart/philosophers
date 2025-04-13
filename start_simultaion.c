/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simultaion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:43:59 by dias              #+#    #+#             */
/*   Updated: 2025/04/13 19:31:33 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	data->start_time = get_current_time();
	if (pthread_create(&monitor, NULL, monitor_routine, data))
		return (1);
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, \
			philo_routine, &data->philos[i]))
			return (1);
		pthread_detach(data->philos[i].thread);
	}
	pthread_join(monitor, NULL);
	return (0);
}
