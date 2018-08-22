/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allentemunovic <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 00:40:49 by allentemu         #+#    #+#             */
/*   Updated: 2018/08/22 16:12:49 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		terminate(int sig)
{
	(void)sig;
	exit(0);
}

/*
** ICANON() - Enables canonical mode (terminal input processed in lines
**			  terminated by newline ('\n'), EOF, or EOL charcters.
** ECHO() - echo the input characters.
** signal() - a simplified interface to mainpulate a process from outside it's
**			  domain, as well as allowing the process to manipulate itself.
** stop_process() - This function listens for a SIGTSTP or 18 signal that stops
**					the signal gernerated from the keyboard.
** tputs() - output commands to the terminal.
** tcsetattr() - set the parameters associated with the terminal.
** tcgetattr() - get the parameters associated with the terminal.
** tgetstr() - returns the string entry fo r id, or zero if it is not available.
** 			   Use tputs() to output the return string.
*/

static void		stop_process(int sig)
{
	t_env			*term;
	char			cp[2];

	(void)sig;
	term = NULL;
	cp[0] = term->termios.c_cc[VSUSP];
	cp[1] = 0;
	term->termios.c_lflag &= ~(ICANON | ECHO);
	signal(18, SIG_DFL);
	if (tcsetattr(0, TCSADRAIN, &term->termios) == -1)
		write(1, "Cannot retrieve termcap attributes TERM\n", 40);
	tcsetattr(0, 0, &(term->termios));
	tputs(tgetstr("ve", NULL), 1, my_putchar);
	tputs(tgetstr("te", NULL), 1, my_putchar);
	ioctl(0, TIOCSTI, cp);
}

/*
** restart() - This function sends a signal define macro called SIGCONT or 19
**             that continues the process. This signal is special - it always
**			   makes the process contiue if it is stopped, before the signal
**             is delievered.
*/

static void		restart(int sig)
{
	t_env			*term;

	(void)sig;
	term = NULL;
	term = orig_term(&term);
	tcgetattr(term->fd, &term->termios);
	term->termios.c_lflag &= ~(ICANON | ECHO);
	term->termios.c_cc[VMIN] = 1;
	term->termios.c_cc[VTIME] = 0;
	tcsetattr(term->fd, TCSANOW, &term->termios);
	set_signal(term);
	tputs(tgetstr("vi", NULL), 1, my_putchar);
	tputs(tgetstr("ti", NULL), 1, my_putchar);
	window_size_change(sig);
	check_size(term);
}

/*
** window_size_change() - This funciton is generated when the terminal
**						  driver's record of the number of rows and cols
**						  on the screen changes. This helps ignore it.
*/

void			window_size_change(int sig)
{
	t_env			*term;
	struct winsize	winsize;

	(void)sig;
	term = NULL;
	term = orig_term(&term);
	ioctl(0, TIOCGWINSZ, &winsize);
	if (tgetent(NULL, getenv("TERM")) <= 0)
		write(1, "Cannot resize window.\n", 22);
	print_list(term);
}

/*
** set_signal() - Function acts as a dispatch table and listens for any
**                signal sent from the user to be executed.
*/

void			set_signal(t_env *term)
{
	term = orig_term(&term);
	signal(28, window_size_change);
	signal(18, stop_process);
	signal(19, restart);
	signal(2, terminate);
}
