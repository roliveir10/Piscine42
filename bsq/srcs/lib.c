/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:56:30 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/20 13:42:14 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen] = src[i];
		destlen++;
		i++;
	}
	dest[destlen] = 0;
	return (dest);
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

char	*ft_strjoinf(char **str1, char *str2)
{
	int		len;
	char	*fresh;

	len = ft_strlen(*str1) + ft_strlen(str2);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	ft_strcpy(fresh, *str1);
	ft_strcat(fresh, str2);
	free(*str1);
	str1 = NULL;
	return (fresh);
}

char	*ft_filedup(int fd, int *size)
{
	int		ret;
	char	buffer[BUFF_SIZE];
	char	*str;

	ret = 1;
	*size = 0;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE - 1);
		if (ret < 1)
			break ;
		buffer[ret] = '\0';
		str = ft_strjoinf(&str, buffer);
		*size += ret;
	}
	return (str);
}
