/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:15:43 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/08 18:15:22 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				lensrc;

	i = 0;
	while (src[i])
		i++;
	lensrc = i;
	i = 0;
	if (size == 0)
		return (lensrc);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}

static int	ft_next_occurrence(char *str, int index, char *charset, int word)
{
	if (word == 0)
	{
		while (str[index] && !ft_strchr(charset, str[index]))
			index++;
		return (index);
	}
	while (str[index] && ft_strchr(charset, str[index]))
		index++;
	return (index);
}

static int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		i = ft_next_occurrence(str, i, charset, 1);
		if (str[i])
			words++;
		i = ft_next_occurrence(str, i, charset, 0);
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**words_table;
	int		i;
	int		itable;
	int		word_size;

	words = ft_count_word(str, charset) + 1;
	words_table = (char **)malloc(sizeof(char *) * words);
	if (!words_table)
		return (NULL);
	words_table[words - 1] = 0;
	i = 0;
	itable = 0;
	while (str[i])
	{
		i = ft_next_occurrence(str, i, charset, 1);
		if (!str[i])
			return (words_table);
		word_size = ft_next_occurrence(str, i, charset, 0) - i;
		words_table[itable] = malloc(sizeof(char) * (word_size + 1));
		ft_strlcpy(words_table[itable], &str[i], word_size + 1);
		i += word_size;
		itable++;
	}
	return (words_table);
}
