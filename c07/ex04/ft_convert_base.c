/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:33:27 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/07 15:14:14 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

static int	ft_check_base(char *base)
{
	int		baselen;
	int		i;
	int		j;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32)
			return (0);
		i++;
	}
	return (baselen);
}

static void	ft_nbrdup_base(int nbr, char *base, int baselen, char *buffer)
{
	unsigned int	unbr;

	unbr = (unsigned int)nbr;
	if (nbr < 0)
	{
		ft_strncat(buffer, "-", 1);
		unbr = -nbr;
	}
	if (unbr > (unsigned int)baselen - 1)
		ft_nbrdup_base(unbr / baselen, base, baselen, buffer);
	ft_strncat(buffer, &base[unbr % baselen], 1);
}

static int	ft_is_in_base(char c, char *base, int *index)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	int			index;
	int			nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_is_in_base(str[i], base, &index))
	{
		nbr = nbr * ft_strlen(base) + index;
		i++;
	}
	return (nbr * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_base10;
	char	buffer[128];
	int		base_to_len;

	base_to_len = ft_check_base(base_from);
	if (base_to_len == 0)
		return (NULL);
	base_to_len = ft_check_base(base_to);
	if (base_to_len == 0)
		return (NULL);
	nbr_base10 = ft_atoi_base(nbr, base_from);
	if (base_to_len == 0)
		return (NULL);
	buffer[0] = 0;
	ft_nbrdup_base(nbr_base10, base_to, base_to_len, buffer);
	return (ft_strdup(buffer));
}
