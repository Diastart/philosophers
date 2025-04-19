/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:36:20 by dias              #+#    #+#             */
/*   Updated: 2025/04/19 18:09:58 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philos == 1)
	{
		print_status(philo, "has taken left fork");
		ft_sleep(data->time_to_die);
		print_status(philo, "died");
		pthread_mutex_lock(&data->death_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (NULL);
	}
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&data->meal_mutex);
	if (philo->id % 2 == 0)
		ft_sleep(10);
	while (!is_simulation_finished(data))
	{
		philo_eat(philo);
		if (is_simulation_finished(data))
			break ;
		philo_sleep(philo);
		if (is_simulation_finished(data))
			break ;
		philo_think(philo);
	}
	return (NULL);
}
