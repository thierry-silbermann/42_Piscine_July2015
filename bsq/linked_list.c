/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:06:55 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 22:02:04 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BUF_SIZE 1024

t_line_base	*ft_create_elem(char *line)
{
	t_line_base *new_elem;

	new_elem = malloc(sizeof(t_line_base));
	if (new_elem)
	{
		new_elem->line = line;
		new_elem->next = NULL;
	}
	return (new_elem);
}

char		*get_right_buf(int l_l[], int i, int fd)
{
	char	*buf1;
	char	*buf2;

	if ((i + 1 == l_l[0]) && (l_l[1] > 0))
	{
		buf2 = malloc(sizeof(char) * l_l[1]);
		l_l[2] = read(fd, buf2, l_l[1]);
		return (buf2);
	}
	else
	{
		buf1 = malloc(sizeof(char) * BUF_SIZE);
		l_l[2] = read(fd, buf1, BUF_SIZE);
		return (buf1);
	}
}

void		ft_that_norm(int i, t_line_base **ptr_list,
				t_line_base **begin_list, char *buf)
{
	if (i == 0)
	{
		*ptr_list = ft_create_elem(buf);
		*begin_list = *ptr_list;
	}
	else
	{
		(*ptr_list)->next = ft_create_elem(buf);
		*ptr_list = (*ptr_list)->next;
	}
}

t_line_base	*get_next_line(int fd, int size_col)
{
	int			l_l[3];
	t_line_base	*begin_list;
	t_line_base	*ptr_list;
	int			i;
	char		*buf;

	i = 0;
	l_l[0] = (size_col / (BUF_SIZE - 1)) + 1;
	l_l[1] = size_col - (BUF_SIZE - 1) * (size_col / (BUF_SIZE - 1)) + 1;
	while (i < l_l[0])
	{
		buf = get_right_buf(l_l, i, fd);
		if (l_l[2] == 0)
		{
			begin_list = 0;
			break ;
		}
		buf[l_l[2]] = '\0';
		ft_that_norm(i, &ptr_list, &begin_list, buf);
		i++;
	}
	return (begin_list);
}
