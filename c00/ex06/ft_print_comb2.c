/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:44:25 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/01 09:22:48 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_chars(char d1, char u1, char d2, char u2)
{
	ft_putchar(d1);
	ft_putchar(u1);
	ft_putchar(' ');
	ft_putchar(d2);
	ft_putchar(u2);
}

static void	ft_print_du1(char u1, char d1, int start)
{
	while (start < 100)
	{
		ft_print_chars(d1, u1, start / 10 + '0', start % 10 + '0');
		if (u1 == '8' && d1 == '9' && start == 99)
			return ;
		ft_putchar(',');
		ft_putchar(' ');
		start++;
	}
}

void	ft_print_comb2(void)
{
	char	u;
	char	d;
	int		start;

	d = '0';
	while (d <= '9')
	{
		u = '0';
		while (u <= '9')
		{
			start = d % 48 * 10 + u % 48 + 1;
			ft_print_du1(u, d, start);
			u++;
		}
		d++;
	}
}
