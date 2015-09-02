/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 15:03:46 by abungert          #+#    #+#             */
/*   Updated: 2015/07/23 16:10:50 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int			i;
	t_list		*new_list;
	t_list		*new_element;

	i = 0;
	new_list = NULL;
	while (i < ac)
	{
		new_element = ft_create_elem(av[i]);
		new_element->next = new_list;
		new_list = new_element;
		i++;
	}
	return (new_list);
}
