/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:19:11 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/13 21:33:48 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*first;
	t_list	*tmp;

	first = *begin_list;
	while (first && (*cmp)(first->data, data_ref) == 0)
	{
		*begin_list = first->next;
		(*free_fct)(first->data);
		free(first);
		first = *begin_list;
	}
	while (first && first->next)
	{
		if ((*cmp)(first->next->data, data_ref) == 0)
		{
			(*free_fct)(first->next->data);
			if (first->next->next)
				tmp = first->next->next;
			else
				tmp = NULL;
			free(first->next);
			first->next = tmp;
		}
		first = first->next;
	}
}
