/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:41:01 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/06 19:08:53 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *temp;

	temp = *alst;
	while (temp != NULL)
	{
		next = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		(temp) = next;
	}
	*alst = NULL;
}
