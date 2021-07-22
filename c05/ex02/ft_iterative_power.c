/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:29:24 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/05 11:57:37 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	power--;
	while (power > 0)
	{
		nb = nb * tmp;
		power--;
	}
	return (nb);
}
