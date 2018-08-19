#include "../includes/ft_select.h"

static void			turn_on_special_text(t_term *term, int current)
{
	if (term->select[current] == 1)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	if (term->current == current)
		ft_putstr_fd(tgetstr("us", NULL), 2);
}

static void			turn_off_special_text(t_term *term, int current)
{
	if (term->current == current)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
	if (term->select[current] == 1)
		ft_putstr_fd(tgetstr("se", NULL), 2);
}

/*static	void	choose_display(t_arg *lst)
{
	if (lst->select == 1 && lst->cursor == 1)
		print_current_selection(lst->str);
	else if	(lst->cursor == 1)
		print_current(lst->str);
	else if (lst->select == 1)
		print_selected(lst->str);
	else
		ft_putendl_fd(lst->str, 0);
}*/

int			print_list(t_term *term)
{
	int				row;
	int				column;
	int				current;

	row = 0;
	while (row < term->height && row < term->count)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstr_fd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (term->height * column) + row)) < term->count)
		{
			turn_on_special_text(term, current);
			ft_putstr_fd(term->element[current], 2);
			turn_off_special_text(term, current);
			sel_putchar(' ', term->column
							- ft_strlen(term->element[current]), 2);
			column++;
		}
		row++;
	}
	return (0);
}
