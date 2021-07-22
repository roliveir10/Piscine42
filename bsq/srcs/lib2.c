/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:31:07 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/20 21:03:12 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_to_integer(char *str, int size)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < size)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (n);
}

int	ft_str_is_numeric(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n && str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
