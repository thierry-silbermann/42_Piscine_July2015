/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 14:03:18 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 22:05:34 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solve_file(t_map *map, char *filename)
{
	t_solution		*best_sqr;
	t_line_base		*f_line;

	best_sqr = initialize_solution();
	f_line = ft_get_first_line(map);
	best_sqr = search_solution(best_sqr, f_line, map);
	close(map->fd);
	if (best_sqr->max > 0 && map->error == 0)
		ft_print_solution(best_sqr, filename, map);
	else
		ft_puterror("map error\n");
}

void	read_from_args(char *argv)
{
	t_map	*map;
	char	*first_line;
	char	*filename;

	filename = ft_strdup(argv);
	if (!(first_line = ft_get_param(filename)))
		return ;
	if (!(map = ft_init_par_map(first_line)))
		return ;
	map->fd = 3;
	solve_file(map, filename);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			read_from_args(argv[i]);
			i++;
		}
	}
	else if (ft_read_from_stdin())
		read_from_args("my_map");
	else
		ft_puterror("map error\n");
	return (0);
}
