/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:40:44 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 14:41:34 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "lib.h"

void	ft_list_push_back(t_list **begin_list, char *str, char *num, int power)
{
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(str, num, power);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(str, num, power);
}

void	ft_list_push_spoken_back(t_spoken **begin_list, char *str,
			char extra, int len)
{
	t_spoken	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_spoken_elem(str, extra, len);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_spoken_elem(str, extra, len);
}

void	ft_print_list(t_spoken *lst, char color)
{
	t_spoken	*tmp;

	tmp = lst;
	while (lst)
	{
		if (color)
			ft_putstr(lst->color);
		if (lst->word)
			ft_putstr(lst->word);
		if (lst->next && !lst->next->extra && !lst->extra)
			ft_putstr(" ");
		lst = lst->next;
	}
	lst = tmp;
	if (lst)
		ft_putstr("\n");
}
