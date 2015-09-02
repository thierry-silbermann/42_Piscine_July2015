/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 22:32:52 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/26 20:34:02 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_nb_to_str_len(int nb);
char	*ft_int_to_str(int nb);
int		eval_expr(char *str);
int		eval_expr_deep(char *str);
int		get_total(int *tab_nbr, int *tab_op, int count[]);
int		rank(int c);
int		calcul(int a, int b, int c);
int		*get_op(char *str, int count[]);
int		get_str_in_parenthesis(char *str, int *beg, int *end);
char	*get_string(char *str, int beg, int end);
char	*update_formula(char *str, int beg, int end, int total);
int		fuck_the_police(char c);
void	count_nb_and_op(char *str, int count[]);
int		*get_nbr(char *str, int count[]);

#endif
