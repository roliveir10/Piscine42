/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:56:07 by aalkhiro          #+#    #+#             */
/*   Updated: 2021/07/18 19:10:17 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "lib.h"

char	*ft_getcontent(char *path, int argc, char **argv)
{
	int		fd;
	char	*str;
	int		size;

	size = 0;
	fd = -1;
	if (argc < 3)
		fd = open(path, O_RDONLY);
	else if (argc >= 3)
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = ft_filedup(fd, &size);
	close(fd);
	return (str);
}
