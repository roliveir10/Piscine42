/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:47:18 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 21:49:51 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}			t_btree;

typedef struct s_wfile
{
	t_btree			*node;
	int				level;
	int				is_first_elem;
	struct s_wfile	*next;
}				t_wfile;

t_btree	*btree_create_node(void *item);

#endif
