/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 14:12:30 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/21 23:57:36 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	throw_div_error(void)
{
	ft_putstr("Stop : division by zero\n");
	return (0);
}

int	throw_mod_error(void)
{
	ft_putstr("Stop : modulo by zero\n");
	return (0);
}

int	ft_usage(int a, int b)
{
	a = 0;
	b = 0;
	ft_putstr("error : only [ - + * / % ] are accepted.");
	return (0);
}
