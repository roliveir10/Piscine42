/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:03:39 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/08 11:49:34 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putendl(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putendl(par[i].copy);
		i++;
	}
}
