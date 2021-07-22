/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:51:53 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/21 13:47:42 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	ft_special_line(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		if (map->map[i] == -1)
			map->map[i] = 1;
		i++;
	}
	i = 0;
	while (i < map->size * map->height)
	{
		if (map->map[i] == -1)
			map->map[i] = 1;
		i += map->size;
	}
}

static int	ft_get_ushort_tab(char *str, t_map *map)
{
	int		i;
	int		mindex;

	i = map->offset;
	mindex = 0;
	map->map = (short *)malloc(sizeof(short) * (map->size * map->height));
	if (!map->map)
		return (0);
	while (mindex < map->size * map->height)
	{
		if (str[i] == map->rock)
			map->map[mindex] = 0;
		else if (str[i] != '\n')
			map->map[mindex] = -1;
		if (str[i] != '\n')
			mindex++;
		i++;
	}
	ft_special_line(map);
	return (1);
}

void	ft_display_squard(char *str, t_max max, t_map *map)
{
	int	x;
	int	y;

	y = max.y;
	while (y < max.y + max.size)
	{
		x = max.x;
		while (x < max.x + max.size)
		{
			str[map->offset + y * (map->size + 1) + x] = map->full;
			x++;
		}
		y++;
	}
}

static int	ft_file_error(char *file)
{
	free(file);
	return (0);
}

int	file_handler(int fd, t_map *map)
{
	char		*file;
	int			fsize;
	t_max		max;

	fsize = 0;
	file = ft_filedup(fd, &fsize);
	if (!file)
		return (0);
	if (ft_check_file(file, fsize, map) == 0)
		return (ft_file_error(file));
	if (ft_get_ushort_tab(file, map) == 0)
		return (ft_file_error(file));
	max = give_max(map->map, map->size, map->height);
	ft_display_squard(file, max, map);
	write(1, &file[map->offset], fsize - map->offset);
	free(file);
	free(map->map);
	return (1);
}
