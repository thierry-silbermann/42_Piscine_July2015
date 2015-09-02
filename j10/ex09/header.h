/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 14:02:50 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/22 23:16:15 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef int		(*t_s_opp)(int, int);

typedef struct	s_opp
{
	char	*c;
	t_s_opp	func;
}				t_opp;

int				ft_atoi(char *str);
int				ft_add(int a, int b);
int				ft_mul(int a, int b);
int				ft_sub(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				throw_div_error(void);
int				throw_mod_error(void);
int				ft_usage(int a, int b);

#endif
