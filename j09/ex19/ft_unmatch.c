/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:27:26 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/17 13:36:57 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int i;
	int current_i;
	int is_find;

	current_i = 0;
	while (current_i < length)
	{
		i = 0;
		is_find = 0;
		while (i < length)
		{
			if (i != current_i)
				if (tab[i] == tab[current_i])
				{
					is_find = 1;
					break ;
				}
			i++;
		}
		if (!is_find)
			return (tab[current_i]);
		current_i++;
	}
	return (tab[current_i]);
}
