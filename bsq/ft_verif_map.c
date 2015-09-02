/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguthert <jguthert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:58:51 by jguthert          #+#    #+#             */
/*   Updated: 2015/07/30 18:33:37 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_verif_line(char *str, t_map *map)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\n')
	{
		if ((str[i] != map->obstacle_char && str[i] != map->empty_char) ||
			str[i] == '\n')
			return (0);
		i++;
	}
	if (map->nb_col == 0)
		map->nb_col = i;
	else if (i != map->nb_col)
	{
		map->error = 1;
		return (0);
	}
	return (1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_get_nb_line(char *str, int len)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (i < len)
	{
		nb *= 10;
		nb += str[i];
		i++;
	}
	return (nb);
}

int			ft_verif_parm(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	while (i < len)
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	if (str[len - 3] == str[len - 2] || str[len - 1] == str[len - 3] ||
		str[len - 1] == str[len - 2])
		return (0);
	return (len);
}

t_map		*ft_init_par_map(char *str)
{
	t_map	*map;
	int		len;

	if (!(len = ft_verif_parm(str)))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	else
	{
		map->square_char = str[len - 1];
		map->obstacle_char = str[len - 2];
		map->empty_char = str[len - 3];
		map->nb_line = ft_get_nb_line(str, len - 3);
		map->error = 0;
	}
	return (map);
}
