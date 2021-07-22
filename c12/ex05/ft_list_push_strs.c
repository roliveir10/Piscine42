/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:28:48 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/15 18:22:38 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_create_elem(data);
	if (*begin_list)
		first->next = *begin_list;
	*begin_list = first;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*lst;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&lst, strs[i]);
		i++;
	}
	return (lst);
}
