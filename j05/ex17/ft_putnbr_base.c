/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:24:14 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/15 16:12:15 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int final_nbr[100];
	int	size;

	i = 0;
	size = 0;
	if (is_base(base))
	{
		if (nbr < 0)
		{
			nbr -= nbr;
			ft_putchar('-');
		}
		while (base[size])
			size++;
		while (nbr)
		{
			final_nbr[i++] = nbr % size;
			nbr /= size;
		}
		if (i == 0)
			ft_putchar(base[final_nbr[i]]);
		while (--i >= 0)
			ft_putchar(base[final_nbr[i]]);
	}
}
