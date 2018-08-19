#include "../includes/ft_select.h"

/*
** ioctl() function manipulates the underlying device parameter of
** special files
*/

/*
** SIGTSTP - signals a stop procress generated from users keyboard (18)
** SIGCONT - discards signal and continues after stop (19)
** SIGWINCH - window size change (28)
** SIGVTALRM - virtual timer alarm (26)
*/

/*
**-------------CURSOR MOTION------------
** "rc" - String of commands to make the terminal restore the last saved cursor position.
*/

/*
**------------CLEARING PARTS OF THE SCREEN-----------
** "cd" - String of commands to clear the line the cursor is on, and all the lines below 
**	  it, down to the bottom of the screen.
*/

/*
**-------------INITIALIZING--------------
** "ti" - String of commands to put the terminal into whatever special modes are needed 
**        or appropriate for programs that move the cursor nonsequentially around the screen.
** "te" - String of commands to undo what is done by the `ti' string.
*/

/*
**-------------CURSOR VISIBILITY----------
** "vi" - String of commands to make the cursor invisible.
** "ve" - String of commands to return the cursor to normal.
*/

void	resize_window(int sig)
{
	t_term		*term;
	int		i;
	
	i = 0;
	(void)sig;
	term = NULL;
	term = stock(term, 1);
	tputs(tgetstr("rc", NULL), 1, my_putchar);
	tputs(tgetstr("cd", NULL), 1, my_putchar);
	print_list(term);
}

void	suspend_signal(int sig)
{
	t_term	*term;
	char	cp[2];

	(void)sig;
	term = NULL;
	term = stock(term, 1);
	cp[0] = term->termios.c_cc[VSUSP];
	cp[1] = 0;
	term->termios.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(term->fd, TCSANOW, &(term->termios));
	tputs(tgetstr("te", NULL), 1, my_putchar);
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	signal(18, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

/*void	restart_signal(int sig)
{
	t_term	*term;
	int	i;

	(void)sig;
	i = 0;	
	term = NULL;
	term = stock(term, 1);
	term->termios.c_lflag &= ~(ICANON | ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	tcsetattr(term->fd, TCSANOW, &(term->termios));
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	signal(18, SIG_DFL);
	print_list(term);
}*/
