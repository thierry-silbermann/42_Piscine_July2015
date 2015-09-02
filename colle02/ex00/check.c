/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 21:49:07 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 21:51:48 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solution_fail(int solution[])
{
	int i;

	i = 0;
	while (i < 5)
	{
		solution[i] = 0;
		i++;
	}
}

int		check_solution(int solution[])
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (solution[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_in2(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	is_in(int solution[], char beg)
{
	char const	*c[5] = {"oooo-|", "/\\\\/**", "AACCBB", "ACACBB", "ACCABB"};
	int			i;

	i = 0;
	while (i < 5)
	{
		if (solution[i])
		{
			if (!is_in2(c[i], beg))
				solution[i] = 0;
		}
		i++;
	}
}
