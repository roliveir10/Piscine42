/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:09:17 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 11:39:39 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include "ft_cat.h"

static void	print_error(char *path, char *execname)
{
	char	*err;

	err = strerror(errno);
	ft_putstr_fd(2, execname);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, path);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, err);
	ft_putstr_fd(2, "\n");
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*execname;

	i = 0;
	execname = basename(argv[0]);
	if (i == argc - 1)
		ft_display(0);
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-"))
			ft_display(0);
		else
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
			{
				ft_display(fd);
				close(fd);
			}
			else
				print_error(argv[i], execname);
		}
	}
	return (errno);
}
