/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:49:35 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 11:34:25 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"
#include "rush.h"

int	ft_list_error(char ***line, t_list **lst, char **num)
{
	ft_del_words_tables(line);
	if (num)
		ft_strdel(num);
	if (*lst)
	{
		ft_list_clear(*lst);
		*lst = NULL;
	}
	return (0);
}

int	ft_print_error(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	return (1);
}
