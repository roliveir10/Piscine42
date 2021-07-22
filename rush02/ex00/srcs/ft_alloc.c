/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 08:48:01 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 14:10:22 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"
#include "lib.h"

void	ft_list_clear(t_list *begin_list)
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		if (begin_list->word)
			ft_strdel(&begin_list->word);
		if (begin_list->num)
			ft_strdel(&begin_list->num);
		free(begin_list);
		begin_list = tmp;
	}
}

void	ft_spoken_clear(t_spoken *begin_list)
{
	t_spoken	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		if (begin_list->word)
			ft_strdel(&begin_list->word);
		free(begin_list);
		begin_list = tmp;
	}
}

t_spoken	*ft_create_spoken_elem(char *word, char extra, int len)
{
	t_spoken	*new;

	new = (t_spoken *)malloc(sizeof(t_spoken));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_spoken));
	new->word = word;
	new->extra = extra;
	ft_cpy_color(new->color, len);
	new->next = NULL;
	return (new);
}

t_list	*ft_create_elem(char *str, char *num, int power)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->word = str;
	new->power = power;
	new->next = NULL;
	return (new);
}
