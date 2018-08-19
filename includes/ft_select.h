#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
**---------------------------- External Headers -------------------------------
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/param.h>
# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <termios.h>
# include <stdbool.h>

/*
**---------------------------- Macros Definiton -------------------------------
*/

# define ENTER_KEY	10
# define ESCAPE_KEY	27
# define SPC_KEY	32
# define STAR_KEY	42
# define MINUS_KEY	45
# define BSP_KEY	127
# define LEFT_KEY	4479771
# define UP_KEY		4283163
# define RIGHT_KEY	4414235
# define DOWN_KEY	4348699
# define DEL_KEY	2117294875L

# define BLUE		"\033[34m"
# define RESET		"\033[00m"
# define RED		"\033[31m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define CLEAR		"\033[?1049l"
# define CURSOR		"\033[?1049h\033[H"

# define BUFFER		*(unsigned int *)buffer
# define NORM		(tgetstr("me", NULL))

/*
**--------------------------- Struct Definition ------------------------------
*/

typedef struct			s_term
{
	int			fd;
	char			**element;
	int			count;
	unsigned int		*select;
	int			current;
	int			height;
	int			width;
	int			column;
	struct termios		termios;
}				t_term;

/*
**-------------------------- Helping Functions -----------------------------
*/

void		setup_termcap(t_term *term, int argc, char **argv);
void		move_up(t_term *term, int keycode);
void		move_down(t_term *term, int keycode);
void		move_left(t_term *term, int keycode, int new_elem, int pos);
void		move_right(t_term *term, int keycode, int new_elem, int pos);
void		keyhook(t_term *term);
int		my_putchar(int c);
void		sel_putchar(char c, unsigned int nbr, int fd);
void		reset_term(t_term *select);
void		free_list(t_term *select);
int		init_term(t_term *term);
void		select_from_struct(t_term *term, int element);
t_term		*get_struct(t_term *struc);
int		check_empty_args(int argc, char **argv, int i, int j);
void		select_deselect(t_term *term);
int		print_list(t_term *select);
void		clear_screen(int sig);
t_term		*stock(t_term *term, int i);
void		resize_window(int sig);
int		search_longest_element(t_term *term, int i);
void		suspend_signal(int sig);
void		abort_exit(int sig);
void		return_highlighted_words(t_term *term);

#endif
