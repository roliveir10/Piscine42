/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 08:04:12 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 19:16:04 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"
#include "rush.h"

static int	ft_skip_extra_char(char *str, int *zero)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
	{
		*zero = 1;
		i++;
	}
	return (i);
}

static int	ft_get_num(char *str, char **num)
{
	int		wbegin;
	int		wend;
	int		i;
	int		zero;

	wbegin = 0;
	i = 0;
	zero = 0;
	i = ft_skip_extra_char(str, &zero);
	wbegin = i;
	while (ft_strchr("0123456789", str[i]))
		i++;
	wend = i;
	if (wbegin == wend && zero)
		wbegin -= 1;
	while (str[i] && !ft_strchr(":", str[i]))
		i++;
	if (!ft_strchr(":", str[i]) || wbegin == wend)
		return (-1);
	i++;
	*num = ft_strndup(str + wbegin, wend - wbegin);
	if (!*num)
		return (-1);
	return (i);
}

static char	*ft_get_word(char *str)
{
	char	*word;

	word = ft_strtrim(str);
	if (!word)
		return (NULL);
	if (!ft_str_is_printable(word))
	{
		ft_strdel(&word);
		return (NULL);
	}
	return (word);
}

static int	ft_get_power(char *num)
{
	int	len;

	len = ft_strlen(num);
	if (*num != '1' || !ft_is_only_zero(num + 1))
		return (0);
	if (len <= 3)
		return (0);
	return (len - 1);
}

int	ft_build_list(char *content, t_list **lst)
{
	char	**line;
	int		i;
	char	*num;
	char	*word;
	int		index;

	line = ft_split(content, "\n");
	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		index = ft_get_num(line[i], &num);
		if (index == -1)
			return (ft_list_error(&line, lst, NULL));
		word = ft_get_word(&line[i][index]);
		if (!word)
			return (ft_list_error(&line, lst, &num));
		ft_list_push_back(lst, word, num, ft_get_power(num));
		i++;
	}
	ft_del_words_tables(&line);
	return (1);
}
