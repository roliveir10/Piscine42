/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:48:32 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 17:23:41 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"
#include "lib.h"

static int	ft_block_reader(t_data data, char *nbr, t_spoken **sk)
{
	if (ft_str_to_integer(nbr, 3) == 0)
		return (1);
	if (nbr[0] != '0')
	{
		if (ft_french_exept(nbr, data.french, 0)
			&& !ft_display_numeric(data.lst, sk, nbr, 1))
			return (0);
		if (ft_display_numeric(data.lst, sk, "100", 3) == 0)
			return (0);
	}
	data.nbr = nbr + 1;
	if (data.extra && ft_str_to_integer(data.nbr, 2))
		ft_display_extra(sk, " and ");
	return (ft_display_10to99(data, sk));
}

static int	ft_display_partial_block(int rest, t_data data, t_spoken **sk)
{
	int	len;
	int	ret;

	ret = 1;
	if (ft_str_to_integer(data.nbr, rest) == 0)
		return (1);
	len = ft_strlen(data.nbr) - 1;
	if (rest == 1 && ft_french_exept(data.nbr, data.french, len))
		ret = ft_display_numeric(data.lst, sk, data.nbr, rest);
	if (rest == 2)
		ret = ft_display_10to99(data, sk);
	if (!ret)
		return (0);
	if (rest == 1 || rest == 2)
		ft_display_power(data.lst, len, sk);
	return (1);
}

static int	ft_display_init(char *nbr, int *index, int *nbrlen, int *rest)
{
	if (ft_nbrlen_skip_zero(nbr) >= 40)
		return (0);
	*nbrlen = ft_strlen(nbr);
	*index = 0;
	*rest = (*nbrlen) % 3;
	return (1);
}

static t_spoken	*ft_sk_error(t_spoken *sk)
{
	if (sk)
		ft_spoken_clear(sk);
	return (NULL);
}

t_spoken	*ft_display(t_data data)
{
	int			nbrlen;
	int			index;
	int			rest;
	t_spoken	*spoken;

	spoken = NULL;
	if (!ft_display_init(data.nbr, &index, &nbrlen, &rest))
		return (NULL);
	if (ft_is_only_zero(data.nbr))
	{
		ft_display_numeric(data.lst, &spoken, "0", 1);
		return (spoken);
	}
	if (!ft_display_partial_block(rest, data, &spoken))
		return (ft_sk_error(spoken));
	index += rest;
	while (index < nbrlen)
	{
		if (ft_block_reader(data, &data.nbr[index], &spoken) == 0)
			return (ft_sk_error(spoken));
		if (ft_str_to_integer(&data.nbr[index], 3))
			ft_display_power(data.lst, nbrlen - index - 3, &spoken);
		index += 3;
	}
	return (spoken);
}
