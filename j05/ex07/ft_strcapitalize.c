/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 13:42:23 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/14 13:57:51 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		is_upcase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

int		is_lowercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int is_word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_lowercase(str[i]) && is_word == 0)
			str[i] = str[i] + 32;
		else if (is_upcase(str[i]) && is_word == 1)
			str[i] = str[i] + 32;
		if (!(is_alpha(str[i])))
			word = 0;
		else
			word = 1;
		i++;
	}
	return (str);
}
