/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:13:13 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 17:12:12 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "lib.h"

int	ft_display_2digit_english(t_data data, t_spoken **sk)
{
	int		i;
	char	buff[2];
	int		rest;
	int		n;

	i = 0;
	n = ft_str_to_integer(data.nbr, 2);
	rest = n % 10;
	n = (n / 10) * 10;
	buff[0] = n / 10 + '0';
	buff[1] = '0';
	if (ft_display_numeric(data.lst, sk, buff, 2) == 0)
		return (0);
	if (rest && data.extra)
		ft_display_extra(sk, "-");
	if (rest)
		return (ft_display_numeric(data.lst, sk, data.nbr + 1, 1));
	return (1);
}

int	ft_display_2digit_french(t_data data, t_spoken **sk)
{
	int		n;
	int		rest;
	char	buff[2];

	n = ft_str_to_integer(data.nbr, 2);
	if (n <= 70 || (n >= 80 && n <= 90))
		return (ft_display_2digit_english(data, sk));
	rest = n % 10;
	buff[0] = n / 10 - 1 + '0';
	buff[1] = '0';
	if (ft_display_numeric(data.lst, sk, buff, 2) == 0)
		return (0);
	buff[0] = '1';
	buff[1] = rest + '0';
	if (ft_display_numeric(data.lst, sk, buff, 2) == 0)
		return (0);
	return (1);
}

int	ft_french_exept(char *nbr, char french, int power)
{
	int	n;

	if (!french)
		return (1);
	n = ft_str_to_integer(nbr, 3);
	if (power == 0 && n / 100 == 1)
		return (0);
	if (power == 3 && nbr[0] == '1')
		return (0);
	return (1);
}
