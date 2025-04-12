/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:15:40 by dias              #+#    #+#             */
/*   Updated: 2025/04/12 11:22:10 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *message)
{
	t_data		*data;
	long long	timestamp;

	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	timestamp = get_current_time() - data->start_time;
	pthread_mutex_lock(&data->death_mutex);
	if (!data->someone_died && !data->all_ate_enough)
		printf("%lld %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&data->death_mutex);
	pthread_mutex_unlock(&data->print_mutex);
}
