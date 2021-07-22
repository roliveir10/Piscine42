/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:30:20 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 12:34:08 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"

static char	*ft_memalloc(int size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		len;
	int		seplen;
	int		i;

	if (size == 0 || !strs)
		return (malloc(sizeof(char)));
	seplen = ft_strlen(sep);
	len = -seplen + 1;
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]) + seplen;
	i = -1;
	string = ft_memalloc(len);
	if (!string)
		return (NULL);
	while (++i < size)
	{
		ft_strcat(string, strs[i]);
		if (i + 1 < size && sep)
			ft_strcat(string, sep);
	}
	return (string);
}
