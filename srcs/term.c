#include "../includes/ft_select.h"

t_term	*get_struct(t_term *struc)
{
	static t_term	*term = NULL;
	
	if (struc == 0)
		return (term);
	else
		term = struc;
	return (0);
}

/*void	select_from_struct(t_term *term, int element)
{
	term->element = element;
	term->width = 0;
	term->height = 0;
	term->column = 0;
	term->count = 0;
	term->current = 0;
	get_struct(term);
}*/

int	init_term(t_term *term)
{
	struct winsize	win;

	if ((tgetent(NULL, getenv("TERM")) < 1))
		write(1, "Cannot retrieve environment variable Term\n", 42);
	if (tcgetattr(0, &(term->termios)) == -1)
		write(1, "Unable to retrieve terminal information\n", 40);
	term->termios.c_lflag &= ~(ICANON);
	term->termios.c_lflag &= ~(ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	term->width = win.ws_col;
	term->height = win.ws_row;
	if ((tcsetattr(0, 0, &(term->termios)) == -1))
		write(1, "Unable to set the terminal parameters\n", 38);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	tputs(tgetstr("sc", NULL), 1, my_putchar);
	return (1);
}

static void    dispatch_sig(void (*restart_signal)(int))
{
        t_term  *term;
        char    stop;

        term = get_struct(0);
        stop = 26;
        signal(SIGWINCH, resize_window);
        signal(SIGCONT, restart_signal);
        signal(SIGTSTP, suspend_signal);
}

static void    restart(int sig)
{
        t_term  *term;

        (void)sig;
        term = get_struct(NULL);
        init_term(term);
        dispatch_sig(&restart);
        clear_screen(0);
}

void		setup_termcap(t_term *term, int argc, char **argv)
{
	int i;
	
	i = 0;
	term->element = argv + 1;
	term->count = argc - 1;
	term->select = malloc((argc - 1) * sizeof(int));
	ft_bzero(term->select, (argc - 1) * sizeof(int));
	term->current = 0;
	term->column = search_longest_element(term, i) + 2;
	init_term(term);
	dispatch_sig(&restart);
}
