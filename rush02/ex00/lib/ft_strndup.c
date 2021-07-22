/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:14:00 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/17 14:36:12 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"

char	*ft_strndup(char *str, unsigned int n)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	new[n] = 0;
	ft_strncpy(new, str, n);
	return (new);
}
