/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:03:52 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 12:31:21 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "ft_hexdump.h"

static void	ft_print_error(char *path, char *name)
{
	char	*err;

	err = strerror(errno);
	if (name)
	{
		ft_putstr_fd(2, name);
		ft_putstr_fd(2, ": ");
	}
	else
		ft_putstr_fd(2, "ft_hexdump: ");
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
	index = i;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "-C", 2))
		{
			index++;
			if (opt->c)
				return (0);
			opt->c = 1;
		}
		i++;
	}
	return (index);
}

static int	ft_check_ret_read(int ret, t_readline *rd, int fd)
{
	if (ret < 0)
		return (-1);
	if (ret == 0)
	{
		rd->validfile++;
		close(fd);
		return (0);
	}
	return (1);
}

static void	ft_read_file(t_readline *rd, int fd, char ascii)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, rd->line, BUFF_SIZE - rd->restlen);
		if (ft_check_ret_read(ret, rd, fd) < 1)
			return ;
		if (ret != BUFF_SIZE && rd->restlen > 0)
			ft_line_cat_w_rest(rd, &ret);
		if (ret == BUFF_SIZE && ft_filencmp(rd->line, rd->next, BUFF_SIZE))
			ft_line_complete(rd, &ret, ascii);
		else if (!rd->isdouble && ret == BUFF_SIZE
			&& !ft_filencmp(rd->line, rd->next, BUFF_SIZE))
			ft_line_is_in_double(&rd->isdouble);
		else if (ret < BUFF_SIZE && ret > 0 && rd->restlen == 0)
			ft_save_rest(rd, ret);
		rd->addr += (ret + rd->restlen);
	}
}

int	main(int argc, char **argv)
{
	int				fd;
	int				i;
	t_option		opt;
	t_readline		rd;

	opt.c = 0;
	ft_bzero(&rd, sizeof(t_readline));
	i = ft_option(argc, argv, &opt) - 1;
	if (i == argc - 1)
		ft_read_file(&rd, 0, opt.c);
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			ft_print_error(argv[i], basename(argv[0]));
		ft_read_file(&rd, fd, opt.c);
	}
	if (errno && !rd.validfile)
		ft_print_error(argv[i - 1], basename(argv[0]));
	else if (rd.addr > 0 || ft_strlen(rd.rest) > 0)
		ft_display(rd.rest, &rd.addr, rd.restlen, opt.c);
	return (errno);
}
