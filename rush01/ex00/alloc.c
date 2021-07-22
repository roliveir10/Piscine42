/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:28:08 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/10 21:56:30 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

void	ft_free_mat(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(map->lim[i]);
	free(map->lim);
	i = -1;
	while (++i < map->size)
		free(map->map[i]);
	free(map->map);
}

static char	**ft_create_map(int size)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * size);
	if (!map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * size);
		if (!map[i])
			return (NULL);
		ft_bzero(map[i], size);
		i++;
	}
	return (map);
}

static char	**ft_create_limit(int size)
{
	char	**limit;
	int		i;

	limit = (char **)malloc(sizeof(char *) * 4);
	if (!limit)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		limit[i] = (char *)malloc(sizeof(char) * size);
		if (!limit[i])
			return (NULL);
		ft_bzero(limit[i], size);
		i++;
	}
	return (limit);
}

int	ft_alloc_mat(char ***map, char ***limit, int size)
{
	*map = ft_create_map(size);
	*limit = ft_create_limit(size);
	if (!*map || !*limit)
		return (0);
	return (1);
}
