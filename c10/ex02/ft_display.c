/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:48:21 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 13:02:30 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_tail.h"

static void	ft_putbinary_fd(int fd, char *content, int size)
{
	write(fd, content, size);
}

static void	ft_display_content(int fd, int bytes)
{
	char	*str;
	int		offset;
	int		size;

	str = ft_filedup(fd, &size);
	if (!str)
		return ;
	offset = size - bytes;
	if (offset < 0)
		ft_putbinary_fd(1, str, size);
	else
		ft_putbinary_fd(1, str + offset, bytes);
}

static void	ft_print_arg_name(char *name)
{
	ft_putstr_fd(1, "==> ");
	ft_putstr_fd(1, name);
	ft_putstr_fd(1, " <==\n");
}

void	ft_display(int fd, int bytes, int nbrarg, char *name)
{
	if (nbrarg > 1)
		ft_print_arg_name(name);
	ft_display_content(fd, bytes);
}
