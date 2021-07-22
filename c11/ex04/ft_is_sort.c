/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:40:16 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/13 09:21:43 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_ascii_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + i < length)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_rascii_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	return (ft_ascii_sort(tab, length, f) || ft_rascii_sort(tab, length, f));
}
