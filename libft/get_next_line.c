/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 09:37:45 by atemunov          #+#    #+#             */
/*   Updated: 2018/06/30 16:43:52 by atemunov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_buffer(int fd, char **buff, char **line)
{
	if (*buff[fd])
	{
		*line = ft_strdup(buff[fd]);
		buff[fd] = ft_strnew(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

int		find_newline(int fd, char **buff, char **line)
{
	char	*curr;
	char	*ptr;

	if ((curr = ft_strchr(buff[fd], '\n')))
	{
		ptr = buff[fd];
		*curr = '\0';
		*line = ft_strdup(buff[fd]);
		buff[fd] = ft_strdup(curr + 1);
		free(ptr);
		return (1);
	}
	else if (*buff[fd])
		return (find_buffer(fd, buff, line));
	return (0);
}

int		read_tmp(int fd, char **buff)
{
	char		*tmp;
	char		*ptr;
	int			bytes_read;

	tmp = ft_strnew(BUFF_SIZE + 1);
	while ((bytes_read = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (!buff[fd])
			buff[fd] = ft_strdup(tmp);
		else
		{
			ptr = buff[fd];
			buff[fd] = ft_strjoin(buff[fd], tmp);
			free(ptr);
		}
		ft_bzero(tmp, BUFF_SIZE);
	}
	free(tmp);
	return (bytes_read);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*buff[4864];

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (read_tmp(fd, &buff[fd]) < 0)
		return (-1);
	if (find_newline(fd, &buff[fd], line) == 1)
		return (1);
	return (0);
}
