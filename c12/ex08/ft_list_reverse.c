/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:08:22 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 20:12:45 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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

void	ft_list_reverse(t_list **begin_list)
{
	t_list			*new;
	t_list			*first;
	unsigned int	lstsize;

	lstsize = ft_list_size(*begin_list);
	if (lstsize == 0)
		return ;
	new = ft_list_at(*begin_list, lstsize - 1);
	first = new;
	while (--lstsize)
	{
		new->next = ft_list_at(*begin_list, lstsize - 1);
		new = new->next;
	}
	new->next = NULL;
	*begin_list = first;
}
