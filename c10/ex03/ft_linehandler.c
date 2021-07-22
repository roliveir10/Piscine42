/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linehandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:05:44 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 12:30:36 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_line_cat_w_rest(t_readline *rd, int *ret)
{
	ft_filencat(rd->rest, rd->line, rd->restlen, *ret);
	*ret = *ret + rd->restlen;
	ft_filencpy(rd->line, rd->rest, *ret, *ret);
	rd->restlen = 0;
}

void	ft_line_complete(t_readline *rd, int *ret, char ascii)
{
	ft_display(rd->line, &rd->addr, *ret, ascii);
	ft_filencpy(rd->next, rd->line, BUFF_SIZE, BUFF_SIZE);
	ft_bzero(rd->line, BUFF_SIZE);
	rd->isdouble = 0;
}

void	ft_line_is_in_double(int *isdouble)
{
	*isdouble = 1;
	ft_putstr_fd(1, "*\n");
}

void	ft_save_rest(t_readline *rd, int ret)
{
	ft_filencpy(rd->rest, rd->line, ret, BUFF_SIZE);
	rd->restlen = ret;
	rd->addr -= (ret + rd->restlen);
}
