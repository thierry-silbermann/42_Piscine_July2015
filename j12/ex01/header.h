/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 14:02:50 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/24 23:14:42 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# define BUFFER_SIZE 1024

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_display_file(char *prog_name, char *arg);
void	ft_cat(void);
void	ft_error(char *prog_name, char *arg);

#endif
