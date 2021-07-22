/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:51:11 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/10 22:31:26 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_map
{
	char	**map;
	char	**lim;
	int		size;
	int		print;
}				t_map;

int		ft_getlimit(char *str, t_map *map);
int		ft_backtrack(t_map *map, int pos);
int		ft_checkorder(char *lign, int limit, int size);
int		ft_checklimit(t_map *map, int x, int y);
int		ft_alloc_mat(char ***map, char ***limit, int size);
void	ft_free_mat(t_map *map);
void	ft_putchar(char c);
int		ft_isdigit(char c);
void	ft_bzero(void *s, int n);
void	ft_putendl_fd(int fd, char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_map(char **map, int size);

#endif
