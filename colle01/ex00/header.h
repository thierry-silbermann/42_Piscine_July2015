/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:58:14 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/19 18:52:43 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	print_tab(int **tab);
int		**alloc_tab(void);
void	free_tab(int **tab);
int		throw_error(void);
int		populate_tab(int **tab, int size, char **str);
int		is_valid_move(int **tab, int current_nb, int row, int col);
int		try_move(int **tab, int row, int col, int is_reverse);
int		try_move_rev(int **tab, int row, int col, int is_reverse);
int		find_solution(int **tab, int row, int col, int is_reverse);
int		compare_solution(int **tab1, int **tab2);
#endif
