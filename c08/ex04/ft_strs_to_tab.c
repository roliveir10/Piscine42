/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:35:50 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/09 10:14:10 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		slen;

	slen = ft_strlen(src) + 1;
	dup = malloc(sizeof(char) * slen);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_tab;
	int			i;

	stock_tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock_tab[i].size = ft_strlen(av[i]);
		stock_tab[i].str = av[i];
		stock_tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock_tab[i].str = NULL;
	return (stock_tab);
}
