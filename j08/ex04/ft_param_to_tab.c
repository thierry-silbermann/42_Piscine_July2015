/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:06:40 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/20 22:21:08 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

char				*ft_strdup(char *src)
{
	int		i;
	int		src_size;
	char	*new_str;

	i = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	new_str = (char*)malloc(sizeof(*new_str) * (src_size));
	if (new_str == NULL)
		return (NULL);
	while (i < src_size)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[src_size] = '\0';
	return (new_str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *stock;
	int			i;
	int			j;

	i = 0;
	stock = malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		stock[i].size_param = j;
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
