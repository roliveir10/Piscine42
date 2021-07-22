/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:49:07 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/12 13:10:52 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# define BUFF_SIZE 32

void	ft_putstr_fd(int fd, char *str);
void	ft_display(int fd, int bytes, int nbrarg, char *name);
char	*ft_filejoinf(char **str1, char *str2, int s1, int s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);
char	*ft_filedup(int fd, int *size);
int		ft_atoi(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

typedef struct s_option
{
	char	c;
	int		bytes;
	int		first_arg;
	int		valid_arg;
}				t_option;

#endif
