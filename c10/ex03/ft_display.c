/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:48:21 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 12:44:29 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_hexdump.h"

static void	ft_print_addr(unsigned int addr, int count, char ascii)
{
	const char	hex[17] = "0123456789abcdef";
	int			i;

	if (addr)
	{
		ft_print_addr(addr / 16, count + 1, ascii);
		ft_putchar(hex[addr % 16]);
	}
	else
	{
		i = -1;
		if (!ascii)
			i = 0;
		while (++i < 8 - count)
			ft_putchar('0');
	}
}

static void	ft_complete_with_space(int i, char ascii)
{
	while (i < BUFF_SIZE)
	{
		ft_putstr_fd(1, "  ");
		if (i != BUFF_SIZE)
			ft_putchar(' ');
		i++;
		if (i == 8 && ascii)
			ft_putchar(' ');
	}
}

static void	ft_print_hexline(char *str, int size, char ascii)
{
	const char		hex[17] = "0123456789abcdef";
	unsigned char	c;
	int				i;

	i = 0;
	if (size == 0)
		return ;
	ft_putchar(' ');
	if (ascii)
		ft_putchar(' ');
	while (i < size)
	{
		c = (unsigned char)str[i];
		ft_putchar(hex[c / 16]);
		ft_putchar(hex[c % 16]);
		i++;
		if (i != size)
			ft_putchar(' ');
		if (i == 8 && ascii)
			ft_putchar(' ');
	}
	ft_complete_with_space(i, ascii);
}

static void	ft_print_ascii(char *str, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return ;
	ft_putstr_fd(1, "  |");
	while (i < size)
	{
		if (!ft_isprintable(str[i]))
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('|');
}

void	ft_display(char *line, unsigned int *addr, int size, char ascii)
{
	ft_print_addr(*addr, 0, ascii);
	ft_print_hexline(line, size, ascii);
	if (ascii)
		ft_print_ascii(line, size);
	ft_putchar('\n');
	if (size < BUFF_SIZE && size > 0)
	{
		*addr += size;
		ft_print_addr(*addr, 0, ascii);
		ft_putchar('\n');
	}
}
