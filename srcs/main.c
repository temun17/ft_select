/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:03:05 by atemunov          #+#    #+#             */
/*   Updated: 2018/08/14 14:04:45 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	sel_putchar(char c, unsigned int nbr, int fd)
{
	unsigned int	i;
	
	i = 0;
	while (i++ < nbr)
		ft_putchar_fd(c, fd);
}

int	my_putchar(int c)
{
	return(write(2, &c, 1));
}

t_term	*stock(t_term *term, int i)
{
	static t_term *temp = NULL;
	
	if (--i == 0)
		temp = term;
	return (temp);
}

int	main(int argc, char **argv)
{
	t_term		*term;
	unsigned int	i;
	int		j;
	int		element;

	i = 1;
	j = 0;
	element = 0;
	if (argc == 1)
	{
		write(1, "ft_select: arguments missing\n", 29);
		exit(1);
	}
	term = malloc(sizeof(t_term));
	check_empty_args(argc, argv, i, j);
	setup_termcap(term, argc, argv);
	select_from_struct(term, element);
	get_struct(term);
	stock(term, i);
	clear_screen(0);
	keyhook(term);
	return (0);
}
