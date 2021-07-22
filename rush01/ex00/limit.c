/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:05:58 by hcarpent          #+#    #+#             */
/*   Updated: 2021/07/11 10:59:54 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "rush.h"

static int	ft_checkvalue(char c, int size)
{
	if (c >= 1 && c <= size)
		return (1);
	return (0);
}

static int	ft_checklim_mat(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4 * map->size)
	{
		if (!ft_checkvalue(map->lim[i / map->size][i % map->size], map->size))
			return (0);
		i++;
	}
	return (1);
}

int	ft_getlimit(char *str, t_map *map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && x < map->size * 4)
		{
			map->lim[x / map->size][x % map->size] = str[i] - '0';
			x++;
		}
		else
			return (0);
		i++;
		if (str[i] == ' ' && x != map->size * 4)
			i++;
		else if (str[i])
			return (0);
	}
	return (ft_checklim_mat(map));
}

static int	ft_fill_lign(int i, int x, int y, t_map *map)
{
	int		k;
	char	lign[10];

	k = 0;
	while (k < map->size)
	{
		if (i == 0)
			lign[k] = map->map[k][x];
		if (i == 1)
			lign[k] = map->map[map->size - 1 - k][x];
		if (i == 2)
			lign[k] = map->map[y][k];
		if (i == 3)
			lign[k] = map->map[y][map->size - 1 - k];
		k++;
	}
	if (i < 2 && !ft_checkorder(lign, map->lim[i][x], map->size))
		return (0);
	if (i >= 2 && !ft_checkorder(lign, map->lim[i][y], map->size))
		return (0);
	return (1);
}

int	ft_checklimit(t_map *map, int x, int y)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (ft_fill_lign(i, x, y, map) == 0)
			return (0);
	}
	return (1);
}
