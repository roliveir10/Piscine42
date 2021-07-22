/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:49:44 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/01 09:23:17 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n, int max, int time)
{
	int	k;
	int	value;

	k = 0;
	value = 1;
	while (k < max)
	{
		value = value * 10;
		k++;
	}
	if (time && n != 0 && n * 10 < value)
		ft_putchar('0');
	if (n > 9)
		ft_putnbr(n / 10, max, 0);
	ft_putchar(n % 10 + '0');
}

static int	ft_find_max(int n)
{
	int	max;
	int	tmp;

	max = 0;
	tmp = 10 - n;
	while (n)
	{
		max = max * 10 + tmp;
		tmp++;
		n--;
	}
	return (max);
}

static int	ft_check_comb(int comb, int max)
{
	int	tmp;

	if (comb > max)
		return (1);
	while (comb > 9)
	{
		tmp = comb % 10;
		comb = comb * 0.1;
		if (tmp <= comb % 10)
			return (0);
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	comb;
	int	tmp;
	int	max;

	tmp = 0;
	comb = 0;
	while (tmp < n)
	{
		comb = comb * 10 + tmp;
		tmp++;
	}
	max = ft_find_max(n);
	while (comb <= max)
	{
		ft_putnbr(comb, n, 1);
		comb++;
		while (!ft_check_comb(comb, max))
			comb++;
		if (comb <= max)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}
