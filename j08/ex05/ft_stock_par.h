/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:09:51 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/20 18:14:00 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

# include <stdlib.h>

typedef struct	s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_show_tab(struct s_stock_par *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
char				**ft_split_whitespaces(char *str);
char				*ft_strdup(char *src);
#endif
