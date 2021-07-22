/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:44:48 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/11 11:17:03 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	ft_print_error(char *error, int ret)
{
	ft_putendl_fd(2, error);
	return (ret);
}

void	ft_print_map(char **map, int size)
{
	unsigned char	y;
	unsigned char	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(map[y][x] + '0');
			if (x != size - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

static void	ft_option(int argc, char **argv, t_map *map)
{
	int	i;

	i = 2;
	map->size = 0;
	map->print = 0;
	if (argc == 2)
	{
		map->size = 4;
		return ;
	}
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--size") && i + 1 < argc)
			map->size = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "--print"))
		{
			map->print = 1;
			if (map->size == 0)
				map->size = 4;
		}
		i++;
	}
	if (map->size == 0 || map->size > 9)
		map->size = -1;
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		ret;

	ret = 0;
	if (argc < 2)
		return (ft_print_error("Error\n", 1));
	ft_option(argc, argv, &map);
	if (map.size == -1)
		return (ft_print_error("Error\n", 1));
	if (!ft_alloc_mat(&map.map, &map.lim, map.size))
		return (ft_print_error("Error\n", 1));
	if (ft_getlimit(argv[1], &map) == 0)
	{
		ft_free_mat(&map);
		return (ft_print_error("Error\n", 1));
	}
	ret = ft_backtrack(&map, 0);
	if (ret && !map.print)
		ft_print_map(map.map, map.size);
	ft_free_mat(&map);
	if (ret == 0)
		return (ft_print_error("Error\n", 1));
	return (0);
}
