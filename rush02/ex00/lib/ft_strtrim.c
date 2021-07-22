/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:05:36 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 21:21:14 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"

char	*ft_strtrim(char *str)
{
	char	*new;
	int		wbegin;
	int		wend;
	int		i;

	i = 0;
	while (str[i] && ft_strchr(" ", str[i]))
		i++;
	wbegin = i;
	i = ft_strlen(str);
	while (i > 0 && ft_strchr(" ", str[i - 1]))
		i--;
	wend = i;
	if (wend <= wbegin)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (wend - wbegin + 1));
	if (!new)
		return (NULL);
	new[wend - wbegin] = 0;
	ft_strncpy(new, &str[wbegin], wend - wbegin);
	return (new);
}
