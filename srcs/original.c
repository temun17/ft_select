/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:09:43 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:08:35 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
** orig_term() - This function stores the orignal terminfo format.
*/

t_env	*orig_term(t_env **term)
{
	static t_env	*original;

	if (*term == NULL)
		return (original);
	original = *term;
	return (*term);
}
