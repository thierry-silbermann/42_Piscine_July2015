/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:17:53 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/20 16:20:32 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 		1
# define FALSE 		0
# define SUCCESS 	0
# define EVEN_MSG 	"I have a pair number of arguments.\n"
# define ODD_MSG 	"I have an impair number of arguments.\n"
# define EVEN(x)	(!(x % 2))

typedef int	t_bool;
#endif
