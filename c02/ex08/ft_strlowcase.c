/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:57:56 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/01 19:15:15 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
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
			if (str[i] == upletter[j])
				str[i] = letter[j];
			j++;
		}
		i++;
	}
	return (str);
}
