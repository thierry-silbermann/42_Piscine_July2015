/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:47:57 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/15 22:07:04 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_str(char *str, char *base)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	if (!str[0])
		return (0);
	while (str[i++])
	{
		check = 0;
		while (base[j])
		{
			if (str[i] == ' ' || str[i] == '+'
				|| str[i] == '-' || str[i] == str[j])
			{
				check += 1;
				break ;
			}
			j++;
		}
		if (check == 0)
			return (0);
	}
	return (1);
}

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

int		get_nb(char *str, char *base, int i)
{
	int nb;
	int j;

	nb = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				nb *= 10;
				nb += j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (nb);
}

int		ft_power(int nb, int power)
{
	int res;

	res = 1;
	if (power == 0)
		return (1);
	while (power)
	{
		res *= nb;
		power--;
	}
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int	i;
	int nbr;
	int nbr_final;
	int negative;
	int size_base;

	i = 0;
	negative = 1;
	nbr_final = 0;
	size_base = 0;
	if (is_base(base) && check_str(str, base))
	{
		while (str[i] == ' ' || str[i] == '+')
			i++;
		if (str[i++] == '-')
			negative = -1;
		nbr = get_nb(str, base, i);
		while (base[size_base])
			size_base++;
		i = 0;
		nbr *= 10;
		while ((nbr /= 10) > 0)
			nbr_final += (nbr % 10) * ft_power(size_base, i++);
	}
	return (negative * nbr_final);
}
