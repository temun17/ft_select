/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:40:39 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/06 19:50:45 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *n_list;

	n_list = (t_list*)malloc(sizeof(*n_list));
	if (n_list)
	{
		if (!content)
		{
			n_list->content = NULL;
			n_list->content_size = 0;
		}
		else
		{
			n_list->content = malloc(content_size);
			n_list->content = ft_memcpy(n_list->content, content, content_size);
			n_list->content_size = content_size;
		}
		n_list->next = NULL;
	}
	return (n_list);
}
