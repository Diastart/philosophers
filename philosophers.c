/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dias <dias@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:34:16 by dias              #+#    #+#             */
/*   Updated: 2025/04/09 11:25:43 by dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Incorrect inputs\n");
		return (0);
	}
	parse_arguments(av, &data);
	if(init(&data))
	{
		printf("Error during initialization\n")
		return (0);
	}
}