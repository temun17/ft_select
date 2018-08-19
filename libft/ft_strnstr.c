/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:50:41 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/06 19:23:04 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	if (!(s2[j]))
		return ((char *)s1);
	while (s2[count])
		count++;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i] == s2[j] && s1[i] && s2[j] && i < len)
		{
			i++;
			j++;
		}
		if (!(s2[j]))
			return ((char *)&(s1[i - count]));
		i = (i - j) + 1;
	}
	return (NULL);
}
