/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:56:01 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 23:07:20 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_solution(int solution[], int line, int col)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 5)
	{
		if (solution[i++])
			count++;
	}
	if (count == 0)
		ft_putstr("aucune");
	i = 0;
	while (i < 5)
	{
		if (solution[i])
		{
			ft_print(i, line, col);
			if (count > 1)
				ft_putstr(" || ");
			count--;
		}
		i++;
	}
	ft_putstr("\n");
}

void	which_colle(char beg, int solution[], int index)
{
	char const	*c[5] = {"oooo-|", "/\\\\/**", "AACCBB", "ACACBB", "ACCABB"};
	int			i;

	i = 0;
	while (i < 5)
	{
		if (solution[i])
			if (beg != c[i][index])
			{
				//printf("which: '%c' / '%c' / %d\n", beg, c[i][index], index);
				solution[i] = 0;
			}
		i++;
	}
}

int		is_maybe_last(char beg)
{
	char const	*str = "o\\/AC";
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == beg)
			return (1);
		i++;
	}
	return (0);
}

void	print_to_delete(int solution[], char *str)
{
	int i;

	i = 0;
	ft_putstr("[");
	while (i < 5)
	{
		ft_putnbr(solution[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("] / ");
	ft_putstr(str);
	ft_putstr("\n");
}

void	ft_read(int solution[])
{
	int		count_col_base;
	int		count_col;
	int		count_line;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		is_last_line;
	int		first_line;

	count_col = 1;
	count_line = 1;
	count_col_base = 1;
	is_last_line = 0;
	first_line = 1;
	ret = read(0, buf, BUF_SIZE);
	if (!ret)
		solution_fail(solution);
	while (ret && check_solution(solution))
	{
		buf[1] = '\0';
		ft_putstr(buf);
		if (count_line == 1 && count_col_base == 1 && buf[0] == '\n')
			solution_fail(solution);
		// ###  First line ###
		if (first_line)
		{
			if (count_col_base == 1)
			{
				which_colle(buf[0], solution, 0);
				print_to_delete(solution, "beg beg");
				ret = read(0, buf, BUF_SIZE);
				if (!(ret && buf[0] == '\n'))
				{
					count_col_base++;
				}
			}
			if (count_col_base != 1 && is_maybe_last(buf[0]))
			{
				which_colle(buf[0], solution, 1);
				print_to_delete(solution, "beg last");
				ret = read(0, buf, BUF_SIZE);
				buf[1] = '\0';
				ft_putstr(buf);
				if (buf[0] == '\n')
				{
					first_line = 0;
				}
				else
				{
					printf("Fail: Last col char not follow by newline\n");
					solution_fail(solution);
					break ;
				}
			}
			else if (buf[0] != '\n')
			{
				which_colle(buf[0], solution, 4);
				print_to_delete(solution, "beg middle");
			}
			count_col_base++;
		}
		// ###  Last line ###
		else if (((count_col == 1) && (is_maybe_last(buf[0]))) || is_last_line)
		{
			is_last_line = 1;
			if (count_col == 1)
			{
				which_colle(buf[0], solution, 2);
				print_to_delete(solution, "last beg");
				count_line++;
			}
			else if (count_col > 1 && is_maybe_last(buf[0]))
			{
				which_colle(buf[0], solution, 3);
				print_to_delete(solution, "last last");
				ret = read(0, buf, BUF_SIZE);
				buf[1] = '\0';
				ft_putstr(buf);
				if (buf[0] == '\n')
				{
					ret = read(0, buf, BUF_SIZE);
					if (ret)
					{
						printf("Fail: One more line after\n");
						solution_fail(solution);
						break ;
					}
				}
				else
				{
					printf("Fail: Last col char not follow by newline\n");
					solution_fail(solution);
					break ;
				}
			}
			else
			{
				which_colle(buf[0], solution, 4);
				print_to_delete(solution, "last mid");
			}
			count_col++;
		}
		// ###  Middle line ###
		else
		{
			if (count_col > count_col_base + 1)
			{
				printf("Fail: Too much col: %d %d\n", count_col, count_col_base);
				solution_fail(solution);
				break ;
			}
			if (buf[0] == '\n')
			{
				count_line++;
				if (count_col != count_col_base)
				{
					printf("Fail: Not enough col\n");
					solution_fail(solution);
					break ;
				}
				count_col = 1;
			}
			else
			{
				if (count_col == 1 || count_col == count_col_base - 1)
				{
					which_colle(buf[0], solution, 5);
					print_to_delete(solution, "middle");
				}
				else
				{
					if (buf[0] != ' ')
					{
						solution_fail(solution);
						break ;
					}
				}
				count_col++;
			}
		}
		printf("Line: %d / col: %d / %d\n", count_line, count_col, count_col_base);
		ret = read(0, buf, BUF_SIZE);
	}
	print_solution(solution, count_line, count_col_base - 1);
	printf("%d / %d\n", count_line, count_col_base - 1);
}

int		main(void)
{
	int	solution[5];

	assignment(solution);
	ft_read(solution);
	return (0);
}
