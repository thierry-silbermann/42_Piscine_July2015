/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:55:53 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/19 20:52:53 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char c;

	c = 48 + n;
	ft_putchar(c);
}

void	print_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (j == 8)
				ft_putnbr(tab[i][j]);
			else
			{
				ft_putnbr(tab[i][j]);
				ft_putchar(' ');
			}
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int		throw_error(void)
{
	ft_putstr("Erreur\n");
	return (0);
}
