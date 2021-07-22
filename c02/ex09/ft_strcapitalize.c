/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:00:58 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/03 17:01:56 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isword(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

static void	ft_next_word(char **str)
{
	while (**str && !isword(**str))
		(*str)++;
}

static void	ft_skip_word(char **str)
{
	while (**str && isword(**str))
	{
		if (**str >= 'A' && **str <= 'Z')
			**str += 32;
		(*str)++;
	}
}

static void	ft_char_capitalize(char **c)
{
	int			i;

	i = 0;
	while (i < 26)
	{
		if (**c >= 'a' && **c <= 'z')
			**c -= 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		ft_next_word(&str);
		if (*str)
			ft_char_capitalize(&str);
		str++;
		if (*str)
			ft_skip_word(&str);
	}
	return (tmp);
}
