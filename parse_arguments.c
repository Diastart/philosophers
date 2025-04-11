/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:00:47 by dias              #+#    #+#             */
/*   Updated: 2025/04/11 11:53:09 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	invalid_arguments_check(t_data *data)
{
	if (data->num_philos <= 0)
		printf("Number of philos is invalid to start the program\n");
	else if (data->time_to_die <= 0)
		printf("Time to die is invalid to start the program\n");
	else if (data->time_to_eat < 0)
		printf("Time to eat is invalid to start the program\n");
	else if (data->time_to_sleep < 0)
		printf("Time to sleep is invalid to start the program\n");
	else
		return (0);
	return (1);
}

int	parse_arguments(int ac, char *av[], t_data *data)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (invalid_arguments_check(data))
		return (1);
	if (ac == 6)
		data->must_eat_count = ft_atoi(av[5]);
	else
		data->must_eat_count = -1;
	data->someone_died = 0;
	data->all_ate_enough = 0;
	return (0);
}
