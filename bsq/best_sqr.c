/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:50:07 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/30 18:19:50 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_solution	*initialize_solution(void)
{
	t_solution	*best_sqr;

	best_sqr = malloc(sizeof(t_solution));
	best_sqr->x = 0;
	best_sqr->y = 0;
	best_sqr->max = 0;
	return (best_sqr);
}

void		update_solution(unsigned int x, unsigned int y,
		unsigned int max, t_solution *best_sqr)
{
	best_sqr->x = x;
	best_sqr->y = y;
	best_sqr->max = max;
}
