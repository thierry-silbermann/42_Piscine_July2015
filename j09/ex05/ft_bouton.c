/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 22:15:19 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/16 22:26:28 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_bouton(int i, int j, int k)
{
	if (i > j)
	{
		if (j > k)
			return (j);
		else if (i > k)
			return (k);
		else
			return (i);
	}
	else
	{
		if (i > k)
			return (i);
		else if (j > k)
			return (k);
		else
			return (j);
	}
}
