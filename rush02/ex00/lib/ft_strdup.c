/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:05:09 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 10:13:37 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	int		slen;

	slen = ft_strlen(src) + 1;
	dup = malloc(sizeof(char) * slen);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
