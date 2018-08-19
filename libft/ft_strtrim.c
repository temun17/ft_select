/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:16:12 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/06 19:24:22 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	char			*new;

	if (!s)
		return (NULL);
	start = 0;
	while (ESCAPE(s[start]))
		start++;
	if (s[start] == '\0')
	{
		new = ft_strnew(0);
		new[0] = '\0';
		return (new);
	}
	end = ft_strlen(s) - 1;
	while ((ESCAPE(s[end])) && end > 0)
		end--;
	if (!(new = (ft_strsub(s, start, end - start + 1))))
		return (NULL);
	return (new);
}
