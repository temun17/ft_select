/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:38:13 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 13:59:47 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	keycode(t_env *term)
{
	int		should_refresh;

	should_refresh = 1;
	if (term->keycode == ESCAPE_KEY || term->keycode == 113)
		reset_and_complete(0);
	if (term->keycode == SPC_KEY)
		select_deselect(term);
	if (term->keycode == '\n')
		return_highlighted_words(term);
	if (term->keycode == UP_KEY)
		move_up(term);
	if (term->keycode == DOWN_KEY)
		move_down(term);
	else
		should_refresh = 0;
	if (should_refresh)
		window_size_change(0);
	term->keycode = 0;
}
