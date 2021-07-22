/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:42:23 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 19:22:58 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_hexdump.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
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
