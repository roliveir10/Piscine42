/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:41:38 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 19:15:22 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define RUSH_MAX_UINT 4294967295

typedef struct s_list
{
	int				power;
	char			*num;
	char			*word;
	struct s_list	*next;
}				t_list;

typedef struct s_spoken
{
	char				*word;
	char				color[128];
	char				extra;
	struct s_spoken		*next;
}				t_spoken;

typedef struct s_data
{
	struct s_list	*lst;
	struct s_spoken	*spoken;
	char			*nbr;
	char			extra;
	char			color;
	char			french;
	char			unlimited;
	char			is_stdin;
}				t_data;

char		*ft_getcontent(char *path, int argc, char **argv);
t_spoken	*ft_create_spoken_elem(char *word, char extra, int power);
t_list		*ft_create_elem(char *str, char *num, int power);
void		ft_list_push_back(t_list **begin_list, char *str,
				char *num, int power);
void		ft_list_push_spoken_back(t_spoken **begin_list,
				char *word, char extra, int power);
void		ft_list_clear(t_list *begin_list);
void		ft_display_extra(t_spoken **sk, char *str);
void		ft_spoken_clear(t_spoken *begin_list);
int			ft_build_list(char *content, t_list **lst);
t_spoken	*ft_display(t_data data);
void		ft_print_list(t_spoken *lst, char color);
int			ft_list_error(char ***line, t_list **lst, char **num);
int			ft_print_error(int fd, char *str);
int			ft_nbrlen_skip_zero(char *str);
int			ft_is_only_zero(char *str);
void		ft_display_power(t_list *lst, int power, t_spoken **sk);
int			ft_display_10to99(t_data data, t_spoken **sk);
int			ft_display_numeric(t_list *lst, t_spoken **sk, char *nbr, int n);
int			ft_cpy_color(char *dest, int power);
int			ft_display_2digit_english(t_data data, t_spoken **sk);
int			ft_display_2digit_french(t_data data, t_spoken **sk);
int			ft_french_exept(char *nbr, char french, int power);

#endif
