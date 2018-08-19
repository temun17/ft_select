/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:36:37 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/06 19:11:24 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*t;
	size_t	i;

	i = 0;
	if ((t = malloc(size)) == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}
