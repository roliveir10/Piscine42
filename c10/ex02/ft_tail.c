/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:49:40 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 20:03:24 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>
#include "ft_tail.h"

static void	ft_print_error(char *path, char *execname)
{
	char	*err;

	err = strerror(errno);
	if (execname)
	{
		ft_putstr_fd(2, execname);
		ft_putstr_fd(2, ": ");
	}
	else
		ft_putstr_fd(2, "ft_tail: ");
	ft_putstr_fd(2, path);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, err);
	ft_putstr_fd(2, "\n");
}

static int	ft_option(int argc, char **argv, t_option *opt)
{
	int	i;
	int	index;

	i = 1;
	opt->c = 0;
	opt->valid_arg = 0;
	index = i;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "-c", 2))
		{
			index++;
			if (opt->c)
				return (0);
			opt->bytes = ft_atoi(&argv[i][2]);
			if (opt->bytes < 0 && i + 1 < argc)
			{
				opt->bytes = ft_atoi(argv[i + 1]);
				index++;
			}
			opt->c = 1;
		}
		i++;
	}
	return (index);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_option	opt;

	opt.first_arg = ft_option(argc, argv, &opt);
	if (!opt.c || opt.bytes < 0 || opt.first_arg < 2)
		return (1);
	if (opt.first_arg == argc)
		ft_display(0, opt.bytes, 0, argv[0]);
	i = opt.first_arg - 1;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd > 0)
		{
			if (i != opt.first_arg && opt.valid_arg)
				ft_putstr_fd(1, "\n");
			opt.valid_arg++;
			ft_display(fd, opt.bytes, argc - opt.first_arg, argv[i]);
			close(fd);
		}
		else
			ft_print_error(argv[i], basename(argv[0]));
	}
	return (errno);
}
