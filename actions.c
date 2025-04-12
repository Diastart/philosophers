/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:15:40 by dias              #+#    #+#             */
/*   Updated: 2025/04/12 11:39:16 by dias             ###   ########.fr       */
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

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_status(philo, "has taken left fork");
	if (data->num_philos == 1)
	{
		ft_sleep(data->time_to_die + 1);
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		return ;
	}
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	print_status(philo, "has taken right fork");
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->is_eating = 1;
	print_status(philo, "is eating");
	pthread_mutex_unlock(&data->meal_mutex);
	ft_sleep(data->time_to_eat);
	pthread_mutex_lock(&data->meal_mutex);
	philo->meals_eaten++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_sleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}
