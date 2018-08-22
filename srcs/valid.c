/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:51:21 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:09:13 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** This function is an error checker for my command line arguments.
** In other words, the arguments can never be null. They just won't exist.
** I must check the length of my arguments to see if it is valid.
*/

int	check_empty_args(int argc, char **argv, int i, int j)
{
	unsigned int	spaces;

	while (i < argc)
	{
		spaces = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				spaces++;
			j++;
		}
		if (spaces == ft_strlen(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
