/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:39:09 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/11 18:17:21 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

static int	ft_checklign(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if (i != y && map->map[i][x] == map->map[y][x])
			return (0);
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		if (i != x && map->map[y][i] == map->map[y][x])
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkorder(char *lign, int limit, int size)
{
	int		count;
	int		i;
	char	max;

	count = 0;
	i = 0;
	max = -1;
	while (i < size)
	{
		if (lign[i] > max && lign[i] != 0)
		{
			max = lign[i];
			count++;
		}
		else if (lign[i] == 0)
			return (1);
		if (count + (size - lign[i]) < limit)
			return (0);
		i++;
	}
	return (limit == count);
}

static int	ft_check_map(t_map *map, int x, int y)
{
	if (!ft_checklign(map, x, y))
		return (0);
	if (!ft_checklimit(map, x, y))
		return (0);
	return (1);
}

static void	ft_debug(char **map, int size)
{
	ft_putendl_fd(1, "\e[1;1H\e[2J\n");
	ft_print_map(map, size);
}

int	ft_backtrack(t_map *map, int pos)
{
	int		val;
	int		x;
	int		y;

	if (pos == map->size * map->size)
		return (1);
	val = 1;
	while (val < map->size + 1)
	{
		x = pos % map->size;
		y = pos / map->size;
		map->map[y][x] = val;
		if (map->print)
			ft_debug(map->map, map->size);
		if (ft_check_map(map, x, y))
		{
			if (ft_backtrack(map, pos + 1) == 1)
				return (1);
		}
		map->map[y][x] = 0;
		val++;
	}
	return (0);
}
