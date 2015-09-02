/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 15:45:54 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/12 15:45:57 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	define_char(int tab[])
{
	tab[0] = 111;
	tab[1] = 111;
	tab[2] = 111;
	tab[3] = 111;
	tab[4] = 45;
	tab[5] = 124;
}

void	print_line(int tab[], int x, int y, int tmp[])
{
	int tmp_y;
	int tmp_x;

	tmp_x = tmp[1];
	tmp_y = tmp[0];
	if (tmp_y == 0 && tmp_x == 0)
		ft_putchar(tab[0]);
	else if (tmp_y == 0 && tmp_x == x - 1)
		ft_putchar(tab[1]);
	else if (tmp_y == y - 1 && tmp_x == 0)
		ft_putchar(tab[2]);
	else if (tmp_y == y - 1 && tmp_x == x - 1)
		ft_putchar(tab[3]);
	else if (tmp_y == 0 || tmp_y == y - 1)
		ft_putchar(tab[4]);
	else if (tmp_x == 0 || tmp_x == x - 1)
		ft_putchar(tab[5]);
	else
		ft_putchar(' ');
}

int		colle(int x, int y)
{
	int tab[6];
	int tmp[2];

	define_char(tab);
	tmp[0] = 0;
	while (tmp[0] < y)
	{
		tmp[1] = 0;
		while (tmp[1] < x)
		{
			print_line(tab, x, y, tmp);
			tmp[1]++;
		}
		ft_putchar('\n');
		tmp[0]++;
	}
	return (0);
}
