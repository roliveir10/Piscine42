/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:45:27 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/20 21:08:10 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_check_char(t_map *map)
{
	if (map->full < 32 || map->full > 126)
		return (0);
	if (map->rock < 32 || map->rock > 126)
		return (0);
	if (map->empty < 32 || map->empty > 126)
		return (0);
	if (map->height == 0)
		return (0);
	if (map->empty == map->rock)
		return (0);
	if (map->empty == map->full)
		return (0);
	if (map->rock == map->full)
		return (0);
	return (1);
}

static int	ft_valid_char(char c, t_map *map)
{
	if (c == map->empty)
		return (1);
	if (c == map->rock)
		return (1);
	return (0);
}

static int	ft_pre_check_map(t_map *map, char *str, int fsize)
{
	int	i;
	int	x;

	i = map->offset;
	x = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == map->offset)
		return (0);
	map->size = i - map->offset;
	if (fsize != (map->size + 1) * map->height + map->offset)
		return (0);
	return (1);
}

static int	ft_check_map(char *str, int fsize, t_map *map)
{
	int	i;
	int	x;

	i = map->offset;
	x = 0;
	if (ft_pre_check_map(map, str, fsize) == 0)
		return (0);
	while (i < fsize)
	{
		if (str[i] == '\n')
		{
			if (x != map->size)
				return (0);
			x = -1;
		}
		else if (ft_valid_char(str[i], map) == 0)
			return (0);
		i++;
		x++;
	}
	return (1);
}

int	ft_check_file(char *str, int fsize, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < 4 || !str[i])
		return (0);
	map->full = str[i - 1];
	map->rock = str[i - 2];
	map->empty = str[i - 3];
	map->height = ft_str_to_integer(str, i - 3);
	if (ft_str_is_numeric(str, i - 3) == 0)
		return (0);
	map->offset = i + 1;
	if (!ft_check_char(map))
		return (0);
	return (ft_check_map(str, fsize, map));
}
