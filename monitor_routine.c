/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:36:57 by dias              #+#    #+#             */
/*   Updated: 2025/04/19 18:39:17 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philosopher_death(t_data *data, int i)
{
	long long	time_since_last_meal;
	int			already_died;

	pthread_mutex_lock(&data->meal_mutex);
	time_since_last_meal = get_current_time() - data->philos[i].last_meal_time;
	if (!data->philos[i].is_eating && time_since_last_meal > data->time_to_die)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		pthread_mutex_lock(&data->death_mutex);
		already_died = data->someone_died;
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		if (!already_died)
			print_status(&data->philos[i], "died");
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

int	check_all_ate_enough(t_data *data)
{
	int	i;

	if (data->must_eat_count <= 0)
		return (0);
	i = 0;
	while (i < data->num_philos && \
		data->philos[i].meals_eaten >= data->must_eat_count)
		i++;
	if (i == data->num_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->all_ate_enough = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			if (check_philosopher_death(data, i))
				return (NULL);
		}
		if (check_all_ate_enough(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
