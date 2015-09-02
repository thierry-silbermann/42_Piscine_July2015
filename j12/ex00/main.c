/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 18:17:19 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/23 18:54:03 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];

	if (argc == 1)
	{
		ft_puterror("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_puterror("Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
	return (0);
}
