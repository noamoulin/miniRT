/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:33:13 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/03 16:27:26 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*terminate(t_dynastring **line, int *next_line_in_buffer, int a)
{
	char	*linestr;

	append(line, '\0');
	linestr = getstr(*line);
	delete_dynastring(*line);
	*next_line_in_buffer = a;
	return (linestr);
}

char	*error(t_dynastring *line)
{
	delete_dynastring(line);
	return (NULL);
}

int	read_buffer(char *buffer, t_dynastring **line)
{
	static int	reader_index = 0;
	char		current_chr;

	while (1)
	{
		current_chr = buffer[reader_index];
		if (!current_chr || reader_index >= BUFFER_SIZE)
		{
			reader_index = 0;
			return (1);
		}
		append(line, current_chr);
		reader_index++;
		if (current_chr == ENDL)
			return (0);
	}
}

char	*get_next_line(int fd)
{
	t_dynastring	*line;
	static int		next_line_in_buffer = 0;
	static char		buffer[BUFFER_SIZE + 1];
	int				buffer_check;
	int				read_check;

	dynalloc(&line, 1);
	while (1)
	{
		if (next_line_in_buffer)
		{
			buffer_check = read_buffer(buffer, &line);
			if (!buffer_check)
				return (terminate(&line, &next_line_in_buffer, 1));
			next_line_in_buffer = 0;
		}
		read_check = read_file(fd, buffer, &next_line_in_buffer, &line);
		if (read_check)
		{
			if (read_check < 0)
				return (error(line));
			return (terminate(&line, &next_line_in_buffer, 0));
		}
	}
	return (NULL);
}

int	read_file(int fd, char *buffer, int *nlib, t_dynastring **line)
{
	int	read_len;

	read_len = read(fd, buffer, BUFFER_SIZE);
	if (read_len < 1)
	{
		if ((*line)->filled_size)
			return (1);
		return (-1);
	}
	buffer[read_len] = 0;
	*nlib = 1;
	return (0);
}
