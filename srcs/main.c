/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:42:38 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:19:47 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			my_putchar(int c)
{
	return (write(2, &c, 1));
}

static void	input_loop(t_env *term)
{
	while (42)
	{
		print_list(term);
		read(0, &term->keycode, 4);
		keycode(term);
		if (!term->cap_names)
			reset_and_complete(0);
	}
}

int			main(int argc, char **argv)
{
	t_env	*term;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc == 1)
	{
		write(1, "ft_select: arguments missing\n", 29);
		exit(1);
	}
	check_empty_args(argc, argv, i, j);
	term = (t_env *)malloc(sizeof(t_env));
	init_struct(term, argc, argv);
	init_term(term, argc);
	set_signal(term);
	input_loop(term);
}
