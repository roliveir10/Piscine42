/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:10:14 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 21:48:53 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	t_btree	*item;

	if (!root)
		return (NULL);
	item = btree_search_item(root->left, data_ref, cmpf);
	if (item)
		return (item);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	item = btree_search_item(root->right, data_ref, cmpf);
	if (item)
		return (item);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	return (NULL);
}
