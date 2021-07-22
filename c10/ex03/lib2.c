/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:40:56 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 19:24:23 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_hexdump.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isprintable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	ft_filencmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return ((int)(s1[i] - s2[i]));
	return (0);
}

void	ft_bzero(void *str, int n)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
