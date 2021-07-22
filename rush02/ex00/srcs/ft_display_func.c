/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 08:26:56 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 15:28:53 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "rush.h"

int	ft_is_only_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_nbrlen_skip_zero(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_display_numeric(t_list *lst, t_spoken **sk, char *nbr, int n)
{
	char	*word;

	while (lst)
	{
		if (!ft_ncmp(nbr, lst->num, n))
		{
			word = ft_strdup(lst->word);
			ft_list_push_spoken_back(sk, word, 0, 0);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_display_10to99(t_data data, t_spoken **sk)
{
	int		n;

	n = ft_str_to_integer(data.nbr, 2);
	if (n == 0)
		return (1);
	else if (n < 10 && n > 0)
		return (ft_display_numeric(data.lst, sk, data.nbr + 1, 1));
	else if (n < 20)
		return (ft_display_numeric(data.lst, sk, data.nbr, 2));
	if (data.french)
		return (ft_display_2digit_french(data, sk));
	return (ft_display_2digit_english(data, sk));
}

void	ft_display_power(t_list *lst, int power, t_spoken **sk)
{
	char	*word;

	if (power < 3)
		return ;
	power = power - power % 3;
	while (lst)
	{
		if (lst->power == power)
		{
			word = ft_strdup(lst->word);
			ft_list_push_spoken_back(sk, word, 0, power);
		}
		lst = lst->next;
	}
}
