/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:11:35 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:15:29 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** Capabilites Names
** "se" - leave standout mode (generally to highlight some text)
** "so" - string to enter standout mode
** "me" - if any possible appearance modes are on this turns it off.
** "co" - the number of width of the screen.
** "li" - the number of height of the screen.
** "cl" - stirng to clear the entire screen and put cursor at upper left corner.
** "so" - string to enter standout mode.
** "us" - string to turn on underline mode.
*/

void		leave_standout_mode(t_env *term)
{
	if (tgetstr("se", NULL))
		ft_putstr_fd(tgetstr("se", NULL), 0);
	else
		turn_off_appearance_mode(term);
}

void		turn_off_appearance_mode(t_env *term)
{
	if (tgetstr("me", NULL))
		ft_putstr_fd(tgetstr("me", NULL), 0);
	else
		leave_standout_mode(term);
}

int			check_size(t_env *term)
{
	int	column_range;

	column_range = ((tgetnum("co")) / (term->max_length + 1));
	return ((column_range * (tgetnum("li") - 1)) > term->cap_names);
}

void		print_list(t_env *term)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	if (!check_size(term))
		write(1, "Unable to resize window.\n", 25);
	col = 0;
	row = 0;
	while (term->element[i])
	{
		if (term->select_pos[i] == -1)
			continue ;
		(term->select_pos[i]) ? ft_putstr_fd(tgetstr("so", NULL), 0) : 0;
		(i == term->cursor) ? ft_putstr_fd(tgetstr("us", NULL), 0) : 0;
		ft_putstr_fd(GREEN, 2);
		ft_putstr_fd(term->element[i], 0);
		ft_putstr_fd("\n", 0);
		turn_off_appearance_mode(term);
		(term->select_pos[i]) ? ft_putstr_fd(tgetstr("se", NULL), 0) : 0;
		(col == tgetnum("li") - 2) ? (row += term->max_length + 1) : 0;
		col += (col == tgetnum("li") - 2) ? -col : 1;
		i++;
	}
}
