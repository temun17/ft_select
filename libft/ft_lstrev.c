#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	current = *alst;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*alst = prev;
}
