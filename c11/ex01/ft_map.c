/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:22:57 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 21:27:17 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*tabret;
	int	i;

	i = 0;
	tabret = (int *)malloc(sizeof(int) * length);
	if (!tabret)
		return (NULL);
	while (i < length)
	{
		tabret[i] = (*f)(tab[i]);
		i++;
	}
	return (tabret);
}
