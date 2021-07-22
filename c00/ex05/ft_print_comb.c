/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:32:18 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/01 09:22:27 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_cdu(char c, char d, char u)
{
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar(u);
}

void	ft_print_comb(void)
{
	char	u;
	char	d;
	char	c;

	c = '0';
	while (c <= '7')
	{
		d = c + 1;
		while (d <= '8')
		{
			u = d + 1;
			while (u <= '9')
			{
				ft_print_cdu(c, d, u);
				if (c == '7' && d == '8' && u == '9')
					return ;
				ft_putchar(',');
				ft_putchar(' ');
				u++;
			}
			d++;
		}
		c++;
	}
}
