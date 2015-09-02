/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 23:33:38 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/27 00:47:42 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_last_line(int count[], int solution[], char *buf, int ret)
{
	if (count[1] == 1)
	{
		which_colle(buf[0], solution, 2);
		count[2] += 1;
	}
	else if (count[1] > 1 && is_maybe_last(buf[0]))
	{
		which_colle(buf[0], solution, 3);
		ret = read(0, buf, BUF_SIZE);
		buf[1] = '\0';
		if (buf[0] == '\n')
		{
			ret = read(0, buf, BUF_SIZE);
			if (ret)
				solution_fail(solution);
		}
		else
			solution_fail(solution);
	}
	else
		which_colle(buf[0], solution, 4);
}

void	check_middle(int count[], int solution[], char *buf)
{
	if (count[1] > count[0] + 1)
		solution_fail(solution);
	if (buf[0] == '\n')
	{
		count[2] += 1;
		if (count[1] != count[0])
			solution_fail(solution);
		count[1] = 1;
	}
	else
	{
		if (count[1] == 1 || count[1] == count[0] - 1)
			which_colle(buf[0], solution, 5);
		else
		{
			if (buf[0] != ' ')
				solution_fail(solution);
		}
		count[1] += 1;
	}
}

void	check_first_line(int count[], int ret, char *buf, int solution[])
{
	if (count[0] == 1)
	{
		which_colle(buf[0], solution, 0);
		ret = read(0, buf, BUF_SIZE);
		if (!(ret && buf[0] == '\n'))
			count[0]++;
	}
	if (count[0] != 1 && is_maybe_last(buf[0]))
	{
		which_colle(buf[0], solution, 1);
		ret = read(0, buf, BUF_SIZE);
		buf[1] = '\0';
		if (buf[0] == '\n')
			count[3] = 0;
		else
			solution_fail(solution);
	}
	else if (buf[0] != '\n')
		which_colle(buf[0], solution, 4);
}
