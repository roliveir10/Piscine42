/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:12:32 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/07 10:22:32 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*tabrange;
	int	i;

	range = max - min;
	i = 0;
	if (range < 1)
		return (NULL);
	tabrange = malloc(sizeof(int) * range);
	if (!tabrange)
		return (NULL);
	while (i < range)
	{
		tabrange[i] = min + i;
		i++;
	}
	return (tabrange);
}
