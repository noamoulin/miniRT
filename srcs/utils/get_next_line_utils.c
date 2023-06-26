/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:30:49 by nomoulin          #+#    #+#             */
/*   Updated: 2022/12/06 11:03:08 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

void	dynalloc(t_dynastring **str, size_t initial_size)
{
	if (!initial_size)
		initial_size = 1;
	*str = malloc(sizeof(t_dynastring));
	if (!*str)
		return ;
	(*str)->str = malloc(initial_size);
	if (!(*str)->str)
		return ;
	(*str)->allocated_size = initial_size;
	(*str)->filled_size = 0;
}

t_dynastring	*append(t_dynastring **dstr, char chr)
{
	t_dynastring	*reallocated;
	t_dynastring	*tdstr;

	tdstr = *dstr;
	if (!(dstr && *dstr))
		return (NULL);
	if (tdstr->allocated_size == tdstr->filled_size)
	{
		dynalloc(&reallocated, tdstr->allocated_size * 2);
		if (!reallocated)
			return (NULL);
		copy(reallocated->str, tdstr->str, tdstr->filled_size);
		reallocated->allocated_size = tdstr->allocated_size * 2;
		reallocated->str[tdstr->filled_size] = chr;
		reallocated->filled_size = tdstr->filled_size + 1;
		delete_dynastring(tdstr);
		*dstr = reallocated;
		return (*dstr);
	}
	tdstr->str[tdstr->filled_size] = chr;
	tdstr->filled_size++;
	return (*dstr);
}

void	delete_dynastring(t_dynastring	*str)
{
	if (str)
	{
		free(str->str);
		free(str);
	}
}

char	*getstr(t_dynastring *str)
{
	size_t	len;
	char	*cpy;

	if (!str)
		return (NULL);
	len = str->filled_size;
	if (!len)
		return (malloc(0));
	cpy = malloc(str->filled_size);
	if (!cpy)
		return (NULL);
	while (len--)
		cpy[len] = str->str[len];
	return (cpy);
}
