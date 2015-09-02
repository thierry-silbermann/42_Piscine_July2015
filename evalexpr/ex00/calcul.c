/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 19:43:45 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 19:57:00 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	count_nb_and_op(char *str, int count[])
{
	int i;
	int flag_space;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	flag_space = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '/'
				|| str[i] == '*' || str[i] == '%')
		{
			count[1]++;
			flag_space = 1;
		}
		if (str[i] == ' ')
			flag_space = 1;
		if (str[i] >= '0' && str[i] <= '9' && flag_space)
		{
			count[0]++;
			flag_space = 0;
		}
		i++;
	}
}

int		*get_nbr(char *str, int count[])
{
	int nb_nbr;
	int i;
	int current_nb;
	int *tab_nbr;

	count_nb_and_op(str, count);
	tab_nbr = (int*)malloc(sizeof(int) * count[0]);
	i = 0;
	nb_nbr = 0;
	current_nb = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			current_nb = (current_nb * 10) + str[i] - 48;
			if (str[i + 1] < '0' || str[i + 1] > '9' || str[i + 1] == '\0')
			{
				tab_nbr[nb_nbr] = current_nb;
				nb_nbr++;
				current_nb = 0;
			}
		}
		i++;
	}
	return (tab_nbr);
}

int		calcul(int a, int b, int c)
{
	if (c == fuck_the_police('+'))
		return (a + b);
	if (c == fuck_the_police('-'))
		return (a - b);
	if (c == fuck_the_police('/'))
		return (a / b);
	if (c == fuck_the_police('*'))
		return (a * b);
	if (c == fuck_the_police('%'))
		return (a % b);
	return (0);
}

int		rank(int c)
{
	if (c == fuck_the_police('+') || c == fuck_the_police('-'))
		return (1);
	if (c == fuck_the_police('*') || c == fuck_the_police('/')
			|| c == fuck_the_police('%'))
		return (2);
	return (0);
}
