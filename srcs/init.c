/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:07:46 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:16:11 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	init_term(t_env *term, int i)
{
	if ((tgetent(NULL, getenv("TERM")) < 1))
		write(1, "Cannot retrieve environment variable Term\n", 42);
	if (tcgetattr(0, &(term->termios)) == -1)
		write(1, "Unable to retrieve terminal information\n", 40);
	tcgetattr(term->fd, &term->termios);
	term->termios.c_lflag &= ~(ICANON);
	term->termios.c_lflag &= ~(ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	tcsetattr(term->fd, TCSANOW, &term->termios);
	if ((tcsetattr(0, 0, &(term->termios)) == -1))
		write(1, "Unable to set the terminal parameters\n", 38);
	set_signal(term);
	term->max_length = 0;
	term->cursor = 0;
	while (i-- > 0)
		term->select_pos[i] = 0;
	i = -1;
	ft_putstr_fd(tgetstr("vi", NULL), 0);
}

void	init_struct(t_env *term, int argc, char **argv)
{
	term->select_pos = (int*)malloc(argc - 1);
	term->element = ++argv;
	term->argc = --argc;
	term->cap_names = argc;
}
