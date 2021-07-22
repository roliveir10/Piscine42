/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filedup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:27:23 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 09:12:44 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

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
