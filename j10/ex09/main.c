/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 23:01:54 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/22 23:13:39 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "ft_opp.h"

int		main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 4)
		return (0);
	c = argv[2][0];
	i = 0;
	if (c == '/' && !ft_atoi(argv[3]))
		return (throw_div_error());
	if (c == '%' && !ft_atoi(argv[3]))
		return (throw_mod_error());
	while (i < 5)
	{
		if (*gl_opptab[i].c == c)
		{
			ft_putnbr(gl_opptab[i].func(ft_atoi(argv[1]), ft_atoi(argv[3])));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	gl_opptab[5].func(ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putchar('\n');
	return (0);
}
