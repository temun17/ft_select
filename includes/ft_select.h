/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:43:20 by atemunov          #+#    #+#             */
/*   Updated: 2018/08/22 16:35:10 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
**---------------------------- External Headers ------------------------------
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/param.h>
# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

/*
**---------------------------- Macros Definiton -----------------------------
*/

# define ENTER_KEY		13
# define ESCAPE_KEY		27
# define SPC_KEY		32
# define BSP_KEY		127
# define UP_KEY			4283163
# define DOWN_KEY		4348699

# define BLUE			"\033[34m"
# define RESET			"\033[00m"
# define RED			"\033[31m"
# define WHITE			"\033[37m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"

/*
**--------------------------- Struct Definition -----------------------------
*/

typedef struct		s_env
{
	size_t			keycode;
	int				fd;
	char			**element;
	int				argc;
	int				*select_pos;
	int				current_element;
	int				cursor;
	int				cap_names;
	int				max_length;
	struct termios	termios;
}					t_env;

/*
**-------------------------- Helping Functions ------------------------------
*/

int					check_empty_args(int argc, char **argv, int i, int j);
t_env				*orig_term(t_env **term);
void				print_list(t_env *term);
void				set_signal(t_env *term);
void				return_highlighted_words(t_env *term);
void				select_deselect(t_env *term);
void				reset_and_complete(int sig);
void				keycode(t_env *term);
void				init_struct(t_env *term, int argc, char **argv);
void				init_term(t_env *term, int argc);
void				move_up(t_env *term);
void				move_down(t_env *term);
int					my_putchar(int c);
void				window_size_change(int sig);
void				turn_off_appearance_mode(t_env *term);
void				leave_standout_mode(t_env *term);
int					check_size(t_env *term);

#endif
