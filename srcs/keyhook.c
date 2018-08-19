#include "../includes/ft_select.h"

static void	keyhook2(t_term *term, unsigned long keycode, int should_refresh)
{
	if (keycode == UP_KEY)
		move_up(term, keycode);
	else if (keycode == DOWN_KEY)
		move_down(term, keycode);
	else if (keycode == ESCAPE_KEY || keycode == 113)
		abort_exit(0);
	else
		should_refresh = 0;
	if (should_refresh)
		clear_screen(0);
}

void		keyhook(t_term *term)
{
	unsigned long	keycode;
	int		should_refresh;
	int		pos;
	int		new_elem;

	term = get_struct(NULL);
	pos = 0;
	new_elem = 0;
	while (keycode = 0, (read(0, &keycode, 6)) != 0)
	{
		should_refresh = 1;
		if (keycode == SPC_KEY)
			select_deselect(term);
		else if (keycode == ENTER_KEY)
			return_highlighted_words(term);
		else if (keycode == LEFT_KEY)
			move_left(term, keycode, new_elem, pos);
		else if (keycode == RIGHT_KEY)
			move_right(term, keycode, new_elem, pos);
		else
			keyhook2(term, keycode, should_refresh);
	}
}
