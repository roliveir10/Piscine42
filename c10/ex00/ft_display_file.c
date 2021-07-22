/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:49:17 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 09:38:14 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	ft_putstr_fd(int fd, char *str)
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

static void	ft_display_file(int fd)
{
	int		ret;
	char	buffer[2048];

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, 2047);
		if (ret < 1)
		{
			if (ret < 0)
				ft_putstr_fd(2, "Cannot read file.\n");
			break ;
		}
		buffer[ret] = '\0';
		ft_putbinary_fd(1, buffer, ret);
	}
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd(2, "Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, "Cannot read file.\n");
		return (1);
	}
	ft_display_file(fd);
	close(fd);
	return (0);
}
