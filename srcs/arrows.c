/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:49:26 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/21 18:16:06 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	move_down(t_env *term)
{
	term->cursor++;
	while (term->select_pos[term->cursor] == -1 || term->cursor == term->argc)
	{
		(term->select_pos[term->cursor] == -1) ? term->cursor++ : 0;
		(term->cursor == term->argc) ? term->cursor = 0 : 0;
	}
}

void	move_up(t_env *term)
{
	term->cursor--;
	while (term->select_pos[term->cursor] == -1 || term->cursor == -1)
	{
		(term->select_pos[term->cursor] == -1) ? term->cursor-- : 0;
		(term->cursor == -1) ? (term->cursor = term->argc - 1) : 0;
	}
}
