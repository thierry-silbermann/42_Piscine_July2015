/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 20:40:21 by exam              #+#    #+#             */
/*   Updated: 2015/07/24 20:41:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_brainfuck(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)malloc(sizeof(ptr) * 2048);
	while (str[i] != 0)
	{
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] == '[' && *ptr == 0)
			while (str[i] != ']')
				i++;
		if (str[i] == ']' && *ptr != 0)
			while (str[i] != '[')
				i--;
		if (str[i] == '.')
			write(1, ptr, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char z;

	z = '\n';
	if (argc == 2 && argv[1][0])
		ft_brainfuck(argv[1]);
	else
		write(1, &z, 1);
}
