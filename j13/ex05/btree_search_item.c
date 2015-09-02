/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <tsilberm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 17:23:55 by tsilberm          #+#    #+#             */
/*   Updated: 2015/07/25 17:37:12 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void *btree_search_item(t_btree *root,
	void *data_ref, int (*cmpf)(void *, void *))
{
	if (!(root))
		return (0);
	btree_search_item((root)->left, data_ref, cmpf);
	if ((*cmpf)(data_ref, (*root).item) == 0)
		return (root);
	btree_search_item((root)->right, data_ref, cmpf);
	return (0);
}
