/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:01:16 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 10:04:13 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_unbrlen(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}
