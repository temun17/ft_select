#include "../includes/ft_select.h"

void	select_deselect(t_term *term)
{
	if (term->select[term->current] == 1)
		term->select[term->current] = 0;
	else
		term->select[term->current] = 1;
	term->current = (term->current == term->count - 1
			? 0 : term->current + 1);
}

void				abort_exit(int sig)
{
	suspend_signal(sig);
	exit (0);
}
