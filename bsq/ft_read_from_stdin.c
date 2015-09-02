/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_stdin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <jguthert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 20:28:15 by jguthert          #+#    #+#             */
/*   Updated: 2015/07/30 22:14:12 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define BUF_SIZE 1024

t_stock		*ft_init_stock(void)
{
	t_stock		*stock;

	stock = malloc(sizeof(*stock));
	if (stock == NULL)
		return (NULL);
	else
	{
		stock->c = 0;
		stock->i = 0;
		stock->j = 0;
		stock->nb_linked_list = 0;
		stock->ret = 0;
		stock->str = malloc(sizeof(BUF_SIZE));
	}
	return (stock);
}

t_stock		*ft_normi_grrr(t_line_base **line, t_line_base **begin_list,
						t_stock *stock)
{
	if (stock->i == BUF_SIZE - 1)
	{
		stock->str[stock->i + 1] = '\0';
		if (stock->nb_linked_list == 0)
		{
			*begin_list = ft_create_elem(stock->str);
			*line = *begin_list;
		}
		else
		{
			(*line)->next = ft_create_elem(stock->str);
			(*line) = (*line)->next;
		}
		stock->i = -1;
		stock->nb_linked_list += 1;
	}
	return (stock);
}

t_line_base	*ft_get_first_line(t_map *map)
{
	t_line_base	*line;
	t_line_base	*begin_list;
	t_stock		*stock;

	line = NULL;
	begin_list = NULL;
	stock = ft_init_stock();
	stock->ret = read(map->fd, &(stock->c), 1);
	while (stock->ret && stock->c != '\n')
	{
		stock->str[stock->i] = stock->c;
		stock = ft_normi_grrr((&line), (&begin_list), stock);
		stock->i += 1;
		stock->j += 1;
		stock->ret = read(map->fd, &(stock->c), 1);
	}
	stock->str[stock->i] = '\0';
	if (stock->nb_linked_list == 0)
		begin_list = ft_create_elem(stock->str);
	else if (stock->i > 0)
		line->next = ft_create_elem(stock->str);
	map->nb_col = stock->j;
	return (begin_list);
}

char		*ft_get_param(char *argv)
{
	int		fd;
	int		i;
	char	c;
	char	*str;
	int		ret;

	i = 0;
	str = malloc(sizeof(char) * 11);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read (fd, &c, 1);
	while (ret && i < 10 && c != '\n')
	{
		str[i] = c;
		i++;
		ret = read (fd, &c, 1);
	}
	str[i] = '\0';
	return (str);
}

int			ft_read_from_stdin(void)
{
	int		fd;
	char	*buffer;
	int		ret;

	buffer = (char*)malloc(sizeof(char) * 4096);
	if (buffer == NULL)
		return (0);
	fd = open("my_map", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	if (fd == -1)
		return (0);
	while ((ret = read(0, buffer, sizeof(buffer) - 1)))
	{
		buffer[ret] = '\0';
		write(fd, buffer, ft_strlen(buffer));
	}
	if (close(fd) == -1)
		return (0);
	if (buffer == NULL)
		return (0);
	free (buffer);
	return (1);
}
