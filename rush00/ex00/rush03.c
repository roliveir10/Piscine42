/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ajjo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:48:10 by ael-ajjo          #+#    #+#             */
/*   Updated: 2021/07/04 18:24:14 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char a, char b, char c)
{
	int	count;

	count = 1;
	ft_putchar(a);
	while (count < x - 1)
	{
		ft_putchar(b);
		count++;
	}
	if (x > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	print_mid_line(int x, int y)
{
	int	count;

	count = 1;
	while (count < y - 1)
	{
		print_line(x, 'B', ' ', 'B');
		count++;
	}
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	print_line(x, 'A', 'B', 'C');
	if (y > 2)
		print_mid_line(x, y);
	if (y > 1)
		print_line(x, 'A', 'B', 'C');
}
