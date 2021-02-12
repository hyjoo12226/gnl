/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjoo <hyjoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:48:21 by hyjoo             #+#    #+#             */
/*   Updated: 2021/02/08 20:22:49 by hyjoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					cut_save(char **stock, char **line, char *newline)
{
	char			*tmp;

	*newline = '\0';
	*line = ft_strdup(*stock);
	tmp = ft_strdup(newline + 1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int					read_not(char **stock, char **line, int read_size)
{
	char			*newline;

	if (read_size < 0)
		return (-1);
	if (!*stock)
		*stock = ft_strdup("");
	newline = ft_strchr(*stock, '\n');
	if (newline)
		return (cut_save(stock, line, newline));
	else
	{
		*line = *stock;
		*stock = NULL;
		return (0);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		*stock[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	char			*newline;

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		stock[fd] = ft_strjoin(stock[fd], buf);
		newline = ft_strchr(stock[fd], '\n');
		if (newline)
			return (cut_save(&stock[fd], line, newline));
	}
	return (read_not(&stock[fd], line, read_size));
}
