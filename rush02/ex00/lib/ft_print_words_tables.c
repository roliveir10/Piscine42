/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:58:46 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 14:05:35 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_print_words_tables(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putstr("\n");
		i++;
	}
}
