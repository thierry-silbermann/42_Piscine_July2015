/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 13:50:03 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/21 22:33:51 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int						i;
	char					c;
	char const				*op = "+-*/%\0";
	t_op_functions const	func_arr[] = {add, sub, mul, div, mod};

	if (argc != 4)
		return (0);
	c = argv[2][0];
	i = 0;
	if (c == '/' && !ft_atoi(argv[3]))
		return (throw_div_error());
	if (c == '%' && !ft_atoi(argv[3]))
		return (throw_mod_error());
	while (op[i])
	{
		if (op[i] == c)
		{
			ft_putnbr(func_arr[i](ft_atoi(argv[1]), ft_atoi(argv[3])));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_putstr("0\n");
	return (0);
}
