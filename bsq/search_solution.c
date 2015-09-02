/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 18:47:31 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 23:20:10 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

void		fill_first_line(t_line_base *current_line, unsigned *tab,
				t_map *map, t_solution *best_sqr)
{
	unsigned int	i;
	char			*str;
	t_line_base		*tmp;

	while (current_line)
	{
		i = 0;
		str = current_line->line;
		while (str[i])
		{
			(str[i] == map->empty_char) ? (tab[i] = 1) : (i += 0);
			(str[i] == map->obstacle_char) ? (tab[i] = 0) : (i += 0);
			if (str[i] != map->empty_char && str[i] != map->obstacle_char)
			{
				ft_puterror("map error\n");
				exit (0);
			}
			if (tab[i] > best_sqr->max)
				update_solution(0, i, tab[i], best_sqr);
			i++;
		}
		tmp = current_line->next;
		free(current_line);
		current_line = tmp;
	}
}

void		change_value_tab(unsigned int *tab, unsigned int tmp_t[],
			char *str, t_map *map)
{
	unsigned int	i;

	i = tmp_t[2];
	if (i == 0)
	{
		tmp_t[0] = tab[0];
		if (str[i] == map->empty_char)
			tab[i] = 1;
		else if (str[i] == map->obstacle_char)
			tab[i] = 0;
	}
	else if (str[i] == map->obstacle_char)
		tab[i] = 0;
	else
	{
		tmp_t[1] = tab[i];
		tab[i] = 1 + min(min(tab[i - 1], tmp_t[0]), tab[i]);
		tmp_t[0] = tmp_t[1];
	}
}

void		ft_normicouille(t_line_base **current_line)
{
	t_line_base		*tmp;

	tmp = (*current_line)->next;
	free(*current_line);
	(*current_line) = tmp;
}

t_solution	*search_solution(t_solution *best_sqr, t_line_base *current_line,
		t_map *map)
{
	unsigned int	*tab;
	char			*str;
	int				nb_line;
	unsigned int	tmp_t[3];

	tab = malloc(sizeof(unsigned int) * map->nb_col);
	fill_first_line(current_line, tab, map, best_sqr);
	nb_line = 1;
	while ((current_line = get_next_line(map->fd, map->nb_col)))
	{
		while (current_line && (tmp_t[2] = 0) == 0)
		{
			str = current_line->line;
			while (str[tmp_t[2]] && str[tmp_t[2]] != '\n')
			{
				change_value_tab(tab, tmp_t, str, map);
				if (tab[tmp_t[2]] > best_sqr->max)
					update_solution(nb_line, tmp_t[2], tab[tmp_t[2]], best_sqr);
				tmp_t[2]++;
			}
			ft_normicouille(&current_line);
		}
		nb_line++;
	}
	return (best_sqr);
}
