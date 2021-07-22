/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:45:29 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 08:17:57 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"

char	*ft_strjoinf(char **str1, char *str2)
{
	int		len;
	char	*fresh;

	len = ft_strlen(*str1) + ft_strlen(str2);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	ft_strcpy(fresh, *str1);
	ft_strcat(fresh, str2);
	free(*str1);
	str1 = NULL;
	return (fresh);
}
