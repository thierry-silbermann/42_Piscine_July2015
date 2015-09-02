/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:14:21 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/17 12:20:19 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int count;

	count = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
			count++;
		value >>= 1;
	}
	return (count);
}
