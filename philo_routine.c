/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:36:20 by dias              #+#    #+#             */
/*   Updated: 2025/04/19 18:52:57 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	handle_single_philo(t_philo *philo, t_data *data)
{
	print_status(philo, "has taken left fork");
	ft_sleep(data->time_to_die);
	print_status(philo, "died");
	pthread_mutex_lock(&data->death_mutex);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

static void	initialize_philo_time(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&data->meal_mutex);
	if (philo->id % 2 == 0)
		ft_sleep(10);
}

static void	philo_life_cycle(t_philo *philo, t_data *data)
{
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
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philos == 1)
	{
		handle_single_philo(philo, data);
		return (NULL);
	}
	initialize_philo_time(philo, data);
	philo_life_cycle(philo, data);
	return (NULL);
}
