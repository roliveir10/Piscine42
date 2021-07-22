/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:42:23 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 14:41:26 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_tail.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_filencat(char *dest, char *src, int s1, int s2)
{
	int	i;

	i = 0;
	while (i < s2)
	{
		dest[s1 + i] = src[i];
		i++;
	}
	dest[s1 + i] = 0;
	return (dest);
}

char	*ft_filencpy(char *dest, char *src, int s1, int n)
{
	int	i;

	i = 0;
	while (i < s1 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

char	*ft_filejoinf(char **str1, char *str2, int size1, int size2)
{
	int		len;
	char	*fresh;

	len = size1 + size2;
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	ft_filencpy(fresh, *str1, size1, size1);
	ft_filencat(fresh, str2, size1, size2);
	free(*str1);
	*str1 = NULL;
	return (fresh);
}
