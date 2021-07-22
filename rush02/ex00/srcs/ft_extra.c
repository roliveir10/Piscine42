/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:12:48 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 16:34:06 by aalkhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"
#include "rush.h"

void	ft_display_extra(t_spoken **sk, char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	ft_list_push_spoken_back(sk, dup, 1, 0);
}

static int	ft_cpy_blank(char *dest, int ret)
{
	ft_strcpy(dest, "\033[0m");
	return (ret);
}

int	ft_cpy_color(char *dest, int power)
{
	char	*color;
	char	buf[5];
	int		nbr;

	ft_bzero(buf, 4);
	if (power == 0)
		return (ft_cpy_blank(dest, 1));
	color = malloc(sizeof(char));
	if (!color)
		return (ft_cpy_blank(dest, 0));
	color = ft_strjoinf(&color, "\033[38;5;");
	if (!color)
		return (ft_cpy_blank(dest, 0));
	nbr = (power / 3) * 10 + 4;
	buf[0] = nbr / 100 + '0';
	buf[1] = (nbr / 10) % 10 + '0';
	buf[2] = nbr % 10 + '0';
	buf[3] = 'm';
	color = ft_strjoinf(&color, buf);
	if (!color)
		return (ft_cpy_blank(dest, 0));
	ft_strcpy(dest, color);
	ft_strdel(&color);
	return (1);
}
