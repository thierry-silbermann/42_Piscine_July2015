/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/24 18:26:37 by exam              #+#    #+#             */
/*   Updated: 2015/07/24 18:34:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

unsigned char	reverse_bits(unsigned char octet)
{
	int nb;
	int *reverse[8];
	int count;

	nb = octet;
	count = 0;
	while (nb > 0)
	{
		reverse[count] = nb % 2;
		nb = nb / 2;
		count++;
		printf("%i", reverse[count]);
	}
	count = 0;
	nb = 0;
	while (count < 8)
	{
		nb *= 		
	}
	//return (reverse);
}

int		main()
{
	printf("%c", reverse_bits(a));
	return (0);
}
