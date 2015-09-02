/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 22:01:06 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/20 22:15:30 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char **ft_split_whitespaces(char *av)
{
	int i = 0;
	char **tab;
	while (av[i])
		i++;
	
	tab = (char**)malloc(sizeof(char*) * 3);
	tab[0] = (char*)malloc(sizeof(char)*5);
	tab[0][0] = 'a';
	tab[0][1] = 'a';
	tab[0][2] = 'a';
	tab[0][3] = 'a';
	tab[0][4] = '\0';
	tab[1] = (char*)malloc(sizeof(char)*5);
	tab[1][0] = 'b';
	tab[1][1] = 'b';
	tab[1][2] = 'b';
	tab[1][3] = 'b';
	tab[1][4] = '\0';
	tab[2] = 0;
	return (tab);
}
