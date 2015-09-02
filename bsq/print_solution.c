/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 18:22:32 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 22:21:44 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BUF_SIZE (1 + 1)

void	ft_print_solution(t_solution *sol, char *filename, t_map *map)
{
	unsigned int	tmp_x;
	unsigned int	tmp_y;
	int				fd;
	char			buf[BUF_SIZE];
	int				ret;

	tmp_x = 0;
	tmp_y = 0;
	fd = open(filename, O_RDWR);
	ret = read(fd, buf, 1);
	while (ret && buf[0] != '\n')
		ret = read(fd, buf, 1);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		if (tmp_x >= (sol->x - sol->max + 1) && tmp_x <= sol->x
				&& tmp_y >= (sol->y - sol->max + 1) && tmp_y <= sol->y)
			ft_putchar(map->square_char);
		else
			ft_putchar(buf[0]);
		tmp_y++;
		(buf[0] == '\n') ? (tmp_x += 1, tmp_y = 0) : (tmp_x += 0);
	}
	close(fd);
}
