/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:26:14 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/15 18:22:54 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_create_elem(data);
	if (*begin_list)
		first->next = *begin_list;
	*begin_list = first;
}

static void	ft_swap(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data) > 0)
		{
			ft_swap(&tmp->data, &tmp->next->data);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
