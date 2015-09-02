/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 20:56:31 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/27 00:07:33 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 1
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_print(int colle, int line, int col);
void	solution_fail(int solution[]);
int		check_solution(int solution[]);
void	print_solution(int solution[], int line, int col);
int		is_in2(char const *str, char c);
void	is_in(int solution[], char beg);
void	which_colle(char beg, int solution[], int index);
int		is_maybe_last(char beg);
void	ft_read(int solution[], int count[], int ret, char *buf);
void	assignment(int tab[]);
void	assignment2(int tab[]);
void	check_last_line(int count[], int solution[], char *buf, int ret);
void	check_middle(int count[], int solution[], char *buf);
void	check_first_line(int count[], int ret, char *buf, int solution[]);

#endif
