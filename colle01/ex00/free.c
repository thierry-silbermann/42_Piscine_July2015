/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 18:58:42 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/19 21:02:04 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**alloc_tab(void)
{
	int i;
	int j;
	int **tab;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * 9);
	while (i < 9)
	{
		tab[i] = (int *)malloc(sizeof(int) * 9);
		j = 0;
		while (j < 9)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	free_tab(int **tab)
{
	int i;

	i = 0;
	while (i < 9)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
