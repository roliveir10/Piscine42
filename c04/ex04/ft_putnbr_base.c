/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:28:42 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/05 14:17:44 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_print_base(unsigned int nbr, int baselen, char *base)
{
	if (nbr > (unsigned int)baselen - 1)
		ft_print_base(nbr / baselen, baselen, base);
	ft_putchar(base[nbr % baselen]);
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (baselen);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				baselen;
	unsigned int	unbr;

	unbr = (unsigned int)nbr;
	baselen = ft_check_base(base);
	if (baselen == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = -nbr;
	}
	baselen = ft_strlen(base);
	ft_print_base(unbr, baselen, base);
}
