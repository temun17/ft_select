/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:43:30 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/07 13:45:57 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_find_word(char const *s, char c, size_t *index)
{
	int				i;
	unsigned		start;
	char			*word;

	i = 0;
	while (s[*index] == c && s[*index] != '\0')
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index])
		(*index)++;
	word = ft_strnew(*index - start);
	if (!word)
		return (NULL);
	while (start < *index)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**new_str;
	size_t			count;
	size_t			i;
	size_t			j;

	j = 0;
	count = 0;
	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	i = 0;
	new_str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_str)
		return (NULL);
	while (i < count)
		new_str[i++] = ft_find_word(s, c, &j);
	new_str[i] = NULL;
	return (new_str);
}
