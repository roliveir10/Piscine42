/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:50:37 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/22 10:35:42 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF_SIZE 32768

typedef struct s_max
{
	int	x;
	int	y;
	int	size;
}			t_max;

typedef struct s_map
{
	short	*map;
	int		offset;
	int		size;
	int		height;
	char	rock;
	char	empty;
	char	full;
}				t_map;

void	ft_putstr_fd(int fd, char *str);
int		file_handler(int fd, t_map *map);
int		ft_check_file(char *str, int size, t_map *map);
t_max	give_max(short *map, int size, int height);
char	*ft_filedup(int fd, int *size);
int		ft_strlen(char *str);
int		is_fillable(short s);
int		ft_str_is_numeric(char *str, int n);
short	ft_min(short a, short b, short c);
void	fill_box(short *tab, int l, int i);
int		ft_str_to_integer(char *str, int size);

#endif
