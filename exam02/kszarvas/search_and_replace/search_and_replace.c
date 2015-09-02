/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 18:05:16 by exam              #+#    #+#             */
/*   Updated: 2015/07/24 18:23:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_count(char *str)
{
	int nb;

	nb = 0;
	while (*str++)
		nb++;
	return (nb);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*search_and_replace(char *str, char a, char b)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == a)
			str[i] = b;
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 4 && ft_count(av[2]) == 1 && ft_count(av[3]) == 1)
		ft_putstr(search_and_replace(av[1], av[2][0], av[3][0]));
	ft_putchar('\n');
	return (0);
}
