/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 19:57:40 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 20:03:39 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_string(char *str, int beg, int end)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char*)malloc(sizeof(char) * (end - beg + 1));
	while (beg <= end)
	{
		new_str[i] = str[beg];
		i++;
		beg++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		get_str_in_parenthesis(char *str, int *beg, int *end)
{
	int	i;
	int	flag_par;

	i = 0;
	*beg = 0;
	*end = 0;
	flag_par = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			*beg = i + 1;
			flag_par = 1;
		}
		if (str[i] == ')')
		{
			*end = i - 1;
			break ;
		}
		i++;
	}
	return (flag_par);
}

int		*get_op(char *str, int count[])
{
	int	nb_op;
	int	i;
	int	*tab_op;

	count_nb_and_op(str, count);
	tab_op = (int*)malloc(sizeof(int) * (count[1]));
	i = 0;
	nb_op = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '/'
				|| str[i] == '*' || str[i] == '%')
		{
			tab_op[nb_op] = fuck_the_police(str[i]);
			nb_op++;
		}
		i++;
	}
	return (tab_op);
}
