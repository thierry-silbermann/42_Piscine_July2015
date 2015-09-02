/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 17:44:28 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/19 18:59:24 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		compare_solution(int **tab1, int **tab2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (tab1[i][j] != tab2[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		try_move_rev(int **tab, int row, int col, int is_reverse)
{
	int i;

	i = 9;
	while (i > 0)
	{
		if (is_valid_move(tab, i, row, col))
		{
			tab[row][col] = i;
			if ((col + 1) < 9)
				if (find_solution(tab, row, col + 1, is_reverse))
					return (1);
				else
					tab[row][col] = 0;
			else if ((row + 1) < 9)
				if (find_solution(tab, row + 1, 0, is_reverse))
					return (1);
				else
					tab[row][col] = 0;
			else
				return (1);
		}
		i--;
	}
	return (0);
}
