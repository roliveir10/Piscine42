/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:48:02 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/13 09:38:37 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_doop.h"

static void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

static void	ft_calculate(int index, int a, int b)
{
	int	(*function[5])(int, int);

	function[0] = &ft_addition;
	function[1] = &ft_soustraction;
	function[2] = &ft_division;
	function[3] = &ft_multiplication;
	function[4] = &ft_modulo;
	if (index == 2 && b == 0)
		ft_putstr("Stop : division by zero\n");
	else if (index == 4 && b == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(function[index](a, b));
		write(1, "\n", 1);
	}
}

static int	ft_print_null(void)
{
	write(1, "0\n", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	const char	op[5] = "+-/*%";
	int			i;

	i = 0;
	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) > 1)
		return (ft_print_null());
	while (i < 5)
	{
		if (op[i] == argv[2][0])
		{
			ft_calculate(i, ft_atoi(argv[1]), ft_atoi(argv[3]));
			return (0);
		}
		i++;
	}
	return (ft_print_null());
}
