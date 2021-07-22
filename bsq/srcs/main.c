/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:50:14 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/20 19:28:22 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

static int	ft_print_error(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_map	map;

	i = 1;
	if (i == argc && !file_handler(0, &map))
		ft_print_error(2, "map error\n");
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0 || !file_handler(fd, &map))
			ft_print_error(2, "map error\n");
		close(fd);
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}
