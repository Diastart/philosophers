/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:34:16 by dias              #+#    #+#             */
/*   Updated: 2025/04/11 11:33:59 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Number of inputs does not satisfy constraints\n");
		return (0);
	}
	if (parse_arguments(ac, av, &data))
		return (0);
	if (init(&data))
	{
		printf("Error during initialization\n");
		return (0);
	}
}