/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:24:14 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/15 18:29:47 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	t_btree	*tmp;
	int		diff;

	tmp = *root;
	diff = 0;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	while (1)
	{
		diff = (*cmpf)(tmp->item, item);
		if (diff < 0 && tmp->right)
			tmp = tmp->right;
		else if (diff >= 0 && tmp->left)
			tmp = tmp->left;
		else
			break ;
	}
	if (diff < 0)
		tmp->right = btree_create_node(item);
	else if (diff >= 0)
		tmp->left = btree_create_node(item);
}
