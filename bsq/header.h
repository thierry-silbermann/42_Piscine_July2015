/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 13:56:21 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 22:05:41 by jguthert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_stock
{
	char	c;
	int		i;
	int		j;
	int		nb_linked_list;
	int		ret;
	char	*str;
}					t_stock;

typedef struct		s_map
{
	int				fd;
	unsigned int	nb_line;
	unsigned int	nb_col;
	char			empty_char;
	char			obstacle_char;
	char			square_char;
	int				error;
}					t_map;

typedef struct		s_line_base
{
	struct s_line_base	*next;
	char				*line;
}					t_line_base;

typedef struct		s_solution
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	max;
}					t_solution;

t_solution			*initialize_solution(void);
void				update_solution(unsigned int x, unsigned int y,
						unsigned int max, t_solution *best_sqr);
t_line_base			*ft_get_first_line(t_map *map);
int					ft_verif_line(char *str, t_map *map);
char				*ft_get_param(char *argv);
int					ft_read_from_stdin();
t_map				*ft_init_par_map(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_puterror(char *str);
int					ft_strlen(char *str);
char				*ft_strdup(char *src);
t_line_base			*ft_create_elem(char *line);
t_line_base			*get_next_line(int fd, int size_col);
void				ft_print_solution(t_solution *sol, char *filename,
						t_map *map);
t_solution			*search_solution(t_solution *best_sqr, t_line_base *line1,
						t_map *map);

#endif
