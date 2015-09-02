/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 21:28:32 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/19 21:02:01 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		populate_tab(int **tab, int size, char **str)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (str[i + 1][j])
		{
			if (str[i + 1][j] == '.')
				tab[i][j] = 0;
			else if (str[i + 1][j] >= '0' && str[i + 1][j] <= '9')
				if (is_valid_move(tab, str[i + 1][j] - 48, i, j))
					tab[i][j] = str[i + 1][j] - 48;
				else
					return (throw_error());
			else
				return (throw_error());
			j++;
		}
		if (j != 9)
			return (throw_error());
		i++;
	}
	return (1);
}

int		is_valid_move(int **tab, int current_nb, int row, int col)
{
	int i;
	int row_start;
	int col_start;

	i = 0;
	row_start = (row / 3) * 3;
	col_start = (col / 3) * 3;
	while (i < 9)
	{
		if (tab[row][i] == current_nb)
			return (0);
		if (tab[i][col] == current_nb)
			return (0);
		if (tab[row_start + (i % 3)][col_start + (i / 3)] == current_nb)
			return (0);
		i++;
	}
	return (1);
}

int		try_move(int **tab, int row, int col, int is_reverse)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (is_valid_move(tab, i + 1, row, col))
		{
			tab[row][col] = i + 1;
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
		i++;
	}
	return (0);
}

int		find_solution(int **tab, int row, int col, int is_reverse)
{
	if (!(row < 9 && col < 9))
		return (1);
	if (tab[row][col] != 0)
	{
		if ((col + 1) < 9)
			return (find_solution(tab, row, col + 1, is_reverse));
		else if ((row + 1) < 9)
			return (find_solution(tab, row + 1, 0, is_reverse));
		else
			return (1);
	}
	else
	{
		if (is_reverse)
			return (try_move_rev(tab, row, col, is_reverse));
		else
			return (try_move(tab, row, col, is_reverse));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int **tab;
	int **tab_rev;

	tab = alloc_tab();
	tab_rev = alloc_tab();
	if (argc != 10)
		return (throw_error());
	if (!populate_tab(tab, argc, argv))
		return (0);
	populate_tab(tab_rev, argc, argv);
	find_solution(tab, 0, 0, 0);
	find_solution(tab_rev, 0, 0, 1);
	if (compare_solution(tab, tab_rev))
		print_tab(tab);
	else
		ft_putstr("Erreur\n");
	free_tab(tab);
	free_tab(tab_rev);
	return (0);
}
