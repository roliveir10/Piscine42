/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:48:26 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 10:24:31 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# define BUFF_SIZE 2048

void			ft_del_words_tables(char ***tab);
char			*ft_filedup(int fd, int *size);
char			**ft_split(char *str, char *charset);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoinf(char **str1, char *str2);
int				ft_is_space(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_print_words_tables(char **str);
unsigned int	ft_unbrlen(unsigned int nbr);
int				ft_strchr(char *str, char c);
char			*ft_strtrim(char *str);
char			*ft_strdup(char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_ncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n);
int				ft_atoi(char *str);
int				ft_isdigit(char c);
int				ft_str_is_numeric(char *str);
char			*ft_strjoin(int size, char **strs, char *sep);
char			*ft_strndup(char *str, unsigned int n);
int				ft_strslen(char **tab);
void			ft_strdel(char **str);
int				ft_str_to_integer(char *str, int size);
void			ft_bzero(void *str, int n);
int				ft_str_is_printable(char *str);
int				ft_strcmp(char *s1, char *s2);

#endif
