/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 22:25:39 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 20:49:48 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*update_formula(char *str, int beg, int end, int total)
{
	int		i;
	char	*new_str;
	int		new_length;
	int		k;

	new_length = ft_strlen(str) - (end - beg + 1) + ft_nb_to_str_len(total) + 1;
	new_str = malloc(sizeof(char) * new_length);
	i = 0;
	while (str[i] && i <= beg - 1)
	{
		new_str[i] = str[i];
		i++;
	}
	k = i;
	i = 0;
	while (i < ft_nb_to_str_len(total))
		new_str[k++] = ft_int_to_str(total)[i++];
	i = end;
	while (str[i + 1])
		new_str[k++] = str[(i++) + 1];
	new_str[k] = '\0';
	return (new_str);
}

int		get_total(int *tab_nbr, int *tab_op, int count[])
{
	int	i;
	int	total;

	i = 0;
	while (i < count[1])
	{
		if (rank(tab_op[i]) == 2)
		{
			tab_nbr[i] = calcul(tab_nbr[i], tab_nbr[i + 1], tab_op[i]);
			tab_nbr[i + 1] = 0;
			tab_op[i] = fuck_the_police('+');
		}
		i++;
	}
	total = tab_nbr[0];
	i = 0;
	while (i < count[1])
	{
		total = calcul(total, tab_nbr[i + 1], tab_op[i]);
		i++;
	}
	return (total);
}

int		eval_expr_deep(char *str)
{
	int	*tab_nbr;
	int	*tab_op;
	int	count[2];
	int	total;

	tab_nbr = get_nbr(str, count);
	tab_op = get_op(str, count);
	total = get_total(tab_nbr, tab_op, count);
	return (total);
}

int		eval_expr(char *str)
{
	char	*parent;
	int		mid_result;
	int		beg;
	int		end;

	while (get_str_in_parenthesis(str, &beg, &end))
	{
		parent = get_string(str, beg, end);
		mid_result = eval_expr_deep(parent);
		str = update_formula(str, beg - 1, end + 1, mid_result);
	}
	parent = str;
	beg = 0;
	end = ft_strlen(str);
	mid_result = eval_expr_deep(parent);
	return (mid_result);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
