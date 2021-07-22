/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:52:57 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/03 21:02:22 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_is_printable(char c)
{
	if (c < 32 || c == 127)
		return (0);
	return (1);
}

static void	ft_print_char_hexa(unsigned char div, int index)
{
	const char	hex[17] = "0123456789abcdef";
	char		rest;

	if (index < 2)
	{
		ft_print_char_hexa(div / 16, index + 1);
		rest = div % 16;
		ft_putchar(hex[(int)rest]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_printable(str[i]))
		{
			ft_putchar('\\');
			ft_print_char_hexa(str[i], 0);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
