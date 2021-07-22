/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:03:58 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/14 12:30:31 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define BUFF_SIZE 16

typedef struct s_readline
{
	char			line[BUFF_SIZE];
	char			rest[BUFF_SIZE];
	char			next[BUFF_SIZE];
	int				restlen;
	unsigned int	addr;
	int				validfile;
	int				isdouble;

}				t_readline;

void	ft_putstr_fd(int fd, char *str);
char	*ft_filencpy(char *dest, char *src, int s1, int s2);
char	*ft_filencat(char *dest, char *src, int s1, int s2);
char	*ft_strncat(char *dest, const char *src, unsigned int nb);
char	*ft_strcat(char *dest, char *src);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_bzero(void *str, int n);
char	*ft_filedup(int fd, int *size);
int		ft_filencmp(char *s1, char *s2, unsigned int n);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_display(char *str, unsigned int *addr, int size, char ascii);
int		ft_isprintable(char c);
void	ft_line_cat_w_rest(t_readline *rd, int *ret);
void	ft_line_complete(t_readline *rd, int *ret, char ascii);
void	ft_line_is_in_double(int *isdouble);
void	ft_save_rest(t_readline *rd, int ret);

typedef struct s_option
{
	char	c;
}				t_option;

#endif
