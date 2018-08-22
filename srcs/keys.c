/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:56:59 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:17:14 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	reset_and_complete(int sig)
{
	t_env *term;

	(void)sig;
	term = NULL;
	term = orig_term(&term);
	term->termios.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(term->fd, TCSANOW, &term->termios);
	(sig == -1) ? 0 : ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	close(term->fd);
	free(term->select_pos);
	free(term);
	exit(sig);
}

void	select_deselect(t_env *term)
{
	term->select_pos[term->cursor] = (term->select_pos[term->cursor]) ? 0 : 1;
	term->cursor++;
	while (term->cursor == term->argc)
	{
		(term->select_pos[term->cursor] == -1) ? term->cursor++ : 0;
		(term->cursor == term->argc) ? term->cursor = 0 : 0;
	}
}

/*
** return_highlighted_words() - put the cursor in the upper left corner and
** any of the selected words we will return them to the original shell with
** spaces seperated any other words that are selected.
*/

void	return_highlighted_words(t_env *term)
{
	int i;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (term->element[i])
	{
		if (term->select_pos[i] == 1)
		{
			ft_putstr(term->element[i]);
			ft_putchar(' ');
		}
		i++;
	}
	reset_and_complete(-1);
}
