/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 17:05:02 by exam              #+#    #+#             */
/*   Updated: 2015/07/24 17:12:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	c;
	int		i;

	c = 'a';
	i = 0;
	while (i < 26)
	{
		if (i % 2)
			ft_putchar(c + i - 32);
		else
			ft_putchar(c + i);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
