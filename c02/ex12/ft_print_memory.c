/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:29:44 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/19 12:54:18 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_uchar_hexa(unsigned char div, int index)
{
	const char	hex[17] = "0123456789abcdef";
	char		rest;

	if (index < 2)
	{
		ft_print_uchar_hexa(div / 16, index + 1);
		rest = div % 16;
		ft_putchar(hex[(int)rest]);
	}
}

static void	ft_print_address(unsigned long addr, int count)
{
	const char	hex[17] = "0123456789abcdef";
	char		rest;
	int			i;

	if (addr)
	{
		ft_print_address(addr / 16, count + 1);
		rest = addr % 16;
		ft_putchar(hex[(int)rest]);
	}
	else
	{
		i = 0;
		while (i < 16 - count)
		{
			ft_putchar('0');
			i++;
		}
	}
}

static void	ft_print_cont(unsigned char *addr, int size, int offset)
{
	int	i;

	i = 0;
	while (i < offset)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] < 32 || addr[i] >= 127)
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*add;
	unsigned int	i;

	add = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (i)
				ft_print_cont((unsigned char *)(addr + i - 16), 16, 0);
			ft_print_address((unsigned long)(addr + i), 0);
			ft_putchar(':');
			ft_putchar(' ');
		}
		ft_print_uchar_hexa(*(add + i), 0);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	if (i % 16 && i)
		ft_print_cont((unsigned char *)(addr + i - i % 16),
			i % 16, (16 - i % 16) * 2.5);
	return (addr);
}
