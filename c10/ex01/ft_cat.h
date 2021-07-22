/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:15:40 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/08 20:47:59 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define BUFF_SIZE 2048

void	ft_display(int fd);
void	ft_putstr_fd(int fd, char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
