/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:49:17 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 13:15:56 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_cat.h"

void	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

static void	ft_putbinary_fd(int fd, char *content, int size)
{
	write(fd, content, size);
}

void	ft_display(int fd)
{
	int		ret;
	char	buffer[BUFF_SIZE];

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE - 1);
		if (ret < 1)
			break ;
		buffer[ret] = '\0';
		ft_putbinary_fd(1, buffer, ret);
	}
	if (ret < 0)
		ft_putstr_fd(2, "Cannot read file.\n");
}
