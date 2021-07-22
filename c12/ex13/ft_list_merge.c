/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:09:51 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/13 21:34:01 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	tmp = *begin_list1;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = begin_list2;
}
