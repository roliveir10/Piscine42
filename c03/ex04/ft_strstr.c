/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:28:03 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/08 19:29:27 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strncmp(char *s1, char *s2, unsigned int n)
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

char	*ft_strstr(char *str, char *to_find)
{
	int	to_find_len;
	int	i;

	i = 0;
	to_find_len = ft_strlen(to_find);
	while (str[i])
	{
		if (!ft_strncmp(&str[i], to_find, to_find_len))
			return (&str[i]);
		i++;
	}
	if (i == 0)
		return (str);
	return (NULL);
}
