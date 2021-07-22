/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:45:39 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/01 19:16:46 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	const char	letter[27] = "abcdefghijklmnopqrstuvwxyz";
	const char	upletter[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			i;
	int			j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 26)
		{
			if (str[i] == letter[j])
				str[i] = upletter[j];
			j++;
		}
		i++;
	}
	return (str);
}
