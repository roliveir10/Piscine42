/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:06:52 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/05 10:20:04 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	count;

	if (nb < 0)
		return (0);
	count = nb - 1;
	if (nb == 0)
		return (1);
	while (count > 0)
	{
		nb *= count;
		count--;
	}
	return (nb);
}
