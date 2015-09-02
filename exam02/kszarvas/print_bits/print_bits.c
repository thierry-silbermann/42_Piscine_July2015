/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 18:36:19 by exam              #+#    #+#             */
/*   Updated: 2015/07/24 18:47:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	bits[8];
	int		nb;
	int		count;
	char	z;

	nb = octet;
	count = 0;
	while (count < 8)
	{
		bits[count] = nb % 2;
		nb = nb / 2;
		count++;
	}
	while (count - 1 >= 0)
	{
		z = bits[count - 1] + 48;
		write(1, &z, 1);
		count--;
	}
}
