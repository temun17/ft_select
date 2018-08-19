#include "../includes/ft_select.h"

void	move_up(t_term *term, int keycode)
{
	term->current--;
	if (term->current < 0)
		term->current = term->count = -1;
	else
		move_down(term, keycode);
}

void	move_down(t_term *term, int keycode)
{
	term->current++;
	if (term->current > term->count - 1)
		term->current = 0;
	else
		move_up(term, keycode);
}

void	move_right(t_term *term, int keycode, int new_elem, int pos)
{
	if (keycode == RIGHT_KEY)
	{
		new_elem = term->current + term->height;
		if (new_elem >= term->count)
			term->current = pos;
		else
			term->current = new_elem;
	}
	else
		move_left(term, keycode, new_elem, pos);
}

void	move_left(t_term *term, int keycode, int new_elem, int pos)
{
	pos = term->current % term->height;
	if (keycode == LEFT_KEY)
	{
		new_elem = term->current - term->height;
		if (new_elem < 0)
			term->current = new_elem + (term->count / term->height) *
			term->height + (pos < term->height - term->count % term->height)
			* term->height;
		else
			term->current = new_elem;
		if (term->current >= term->count)
			term->current = term->current - term->height;
	}
	else
		move_right(term, keycode, new_elem, pos);
}
