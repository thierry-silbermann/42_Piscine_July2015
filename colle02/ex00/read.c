/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:56:01 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/27 00:48:28 by tsilberm         ###   ########.fr       */
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

void	ft_read(int solution[], int count[], int ret, char *buf)
{
	if (!ret)
		solution_fail(solution);
	while (ret && check_solution(solution))
	{
		buf[1] = '\0';
		if (count[2] == 1 && count[0] == 1 && buf[0] == '\n')
			solution_fail(solution);
		if (count[3])
		{
			check_first_line(count, ret, buf, solution);
			count[0]++;
		}
		else if (((count[1] == 1) && (is_maybe_last(buf[0]))) || count[4])
		{
			count[4] = 1;
			check_last_line(count, solution, buf, ret);
			count[1]++;
		}
		else
			check_middle(count, solution, buf);
		ret = read(0, buf, BUF_SIZE);
	}
	print_solution(solution, count[2], count[0] - 1);
}

int		main(void)
{
	int		solution[5];
	int		count[5];
	int		ret;
	char	buf[BUF_SIZE + 1];

	ret = read(0, buf, BUF_SIZE);
	buf[1] = '\0';
	assignment(solution);
	assignment2(count);
	ft_read(solution, count, ret, buf);
	return (0);
}
