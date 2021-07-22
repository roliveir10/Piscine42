/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:08:18 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/04 21:57:53 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	int			index;
	int			nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	if (ft_check_base(base) == 0)
		return (0);
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
