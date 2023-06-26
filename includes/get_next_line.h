/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:52:45 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/06 11:34:28 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ENDL '\n'

typedef struct s_dynastring
{
	char	*str;
	size_t	allocated_size;
	size_t	filled_size;

}	t_dynastring;

t_dynastring	*append(t_dynastring **line, char chr);
void			dynalloc(t_dynastring **line, size_t size);
void			copy(char *dest, char *src, size_t len);
void			delete_dynastring(t_dynastring	*line);
char			*getstr(t_dynastring *line);
char			*terminate(t_dynastring **line, int *nlib, int a);
char			*get_next_line(int fd);
char			*error(t_dynastring *line);
int				read_buffer(char *buffer, t_dynastring **line);
int				read_file(int fd, char *b, int *nlib, t_dynastring **l);

#endif
