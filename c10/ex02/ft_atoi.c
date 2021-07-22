/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:40:32 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 20:01:53 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;
	int	b;

	i = 0;
	sign = 1;
	nbr = 0;
	b = 0;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		b++;
		i++;
	}
	if (nbr == 0 && !b)
		return (-1);
	return (sign * nbr);
}
