/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onachin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:57:25 by onachin           #+#    #+#             */
/*   Updated: 2021/07/21 11:31:07 by onachin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_fillable(short s)
{
	if (s == -1)
		return (1);
	return (0);
}

short	ft_min(short a, short b, short c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		return (c);
	}
	if (b < c)
		return (b);
	return (c);
}

void	fill_box(short *tab, int l, int i)
{
	tab[i] = ft_min(tab[i - 1], tab[i - l - 1], tab[i - l]) + 1;
}

void	fill_tab(short *tab, int l, int h)
{
	int		i;
	int		total_size;

	i = 0;
	total_size = l * h;
	while (i < total_size)
	{
		if (is_fillable(tab[i]))
			fill_box(tab, l, i);
		i++;
	}
}

t_max	give_max(short *tab, int l, int h)
{
	t_max	max;
	int		i;
	int		j;

	max.x = 0;
	max.y = 0;
	max.size = 0;
	i = 0;
	fill_tab(tab, l, h);
	while (i < h)
	{
		j = 0;
		while (j < l)
		{
			if (tab[i * l + j] > max.size)
			{
				max.size = tab[i * l + j];
				max.x = j - max.size + 1;
				max.y = i - max.size + 1;
			}
			j++;
		}
		i++;
	}
	return (max);
}
