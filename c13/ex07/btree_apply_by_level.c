/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:22:44 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/16 12:18:53 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

static t_wfile	*ft_create_wfile_elem(t_btree *node, int level)
{
	t_wfile	*new;

	new = (t_wfile *)malloc(sizeof(t_wfile));
	if (!new)
		return (NULL);
	new->node = node;
	new->level = level;
	new->is_first_elem = 0;
	new->next = NULL;
	return (new);
}

static void	ft_push_wfile_back(t_wfile **wfile, t_btree *node, int level)
{
	t_wfile	*tmp;

	tmp = *wfile;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_wfile_elem(node, level);
}

static void	ft_free_wfile_list(t_wfile **wfile)
{
	if ((*wfile) && (*wfile)->next)
		ft_free_wfile_list(&(*wfile)->next);
	free(*wfile);
}

t_wfile	*init_wfile(t_btree *root, int *level, int *cur_level)
{
	t_wfile	*wfile;

	*level = 0;
	*cur_level = 0;
	if (!root)
		return (NULL);
	wfile = ft_create_wfile_elem(root, *level);
	return (wfile);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_wfile	*wfile;
	t_wfile	*tmp;
	int		level;
	int		cur_level;

	wfile = init_wfile(root, &level, &cur_level);
	if (!wfile)
		return ;
	tmp = wfile;
	while (tmp)
	{
		if (cur_level < tmp->level + 1)
		{
			cur_level++;
			tmp->is_first_elem = 1;
		}
		(*applyf)(tmp->node->item, tmp->level, tmp->is_first_elem);
		if (tmp->node->left)
			ft_push_wfile_back(&wfile, tmp->node->left, tmp->level + 1);
		if (tmp->node->right)
			ft_push_wfile_back(&wfile, tmp->node->right, tmp->level + 1);
		tmp = tmp->next;
	}
	ft_free_wfile_list(&wfile);
}
