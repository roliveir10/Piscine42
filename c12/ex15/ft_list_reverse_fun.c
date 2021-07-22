/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:33:05 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/13 21:35:24 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_swap(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

static int	ft_list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}

static t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	size;
	t_list			*last;
	t_list			*first;
	unsigned int	i;

	i = 0;
	size = ft_list_size(begin_list);
	first = begin_list;
	while (i < size / 2)
	{
		last = ft_list_at(begin_list, size - 1 - i);
		ft_swap(&last->data, &first->data);
		first = first->next;
		i++;
	}
}
