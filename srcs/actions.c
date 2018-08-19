#include "../includes/ft_select.h"

int	search_longest_element(t_term *term, int i)
{
	int	max_length;
	int	current_length;

	max_length = 0;
	while (i < term->count)
	{
		current_length = ft_strlen((char*)term->element[i]);
		if (current_length > max_length)
			max_length = current_length;
		i++;
	}
	return (max_length);
}

void			return_highlighted_words(t_term *term)
{
	int				i;
	int				print_space_p;

	suspend_signal(0);
	print_space_p = 0;
	i = 0;
	while (i < term->count)
	{
		if (term->select[i])
		{
			if (print_space_p)
				ft_putchar(' ');
			ft_putstr(term->element[i]);
			print_space_p = 1;
		}
		i++;
	}
	exit(0);
}
