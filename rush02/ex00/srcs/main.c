/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 09:51:48 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/18 19:27:33 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"
#include "rush.h"

static int	ft_test_arg(char *str, char unlimited)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	if (!ft_str_is_numeric(str))
		return (0);
	if (unlimited)
		return (1);
	while (str[i])
	{
		n = n * 10 + str[i] - 48;
		i++;
		if (n > RUSH_MAX_UINT)
			return (0);
	}
	return (1);
}

static int	ft_option(t_data *data, int argc, char **argv)
{
	int	i;

	i = 3;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--extra"))
			data->extra = 1;
		else if (!ft_strcmp(argv[i], "--color"))
			data->color = 1;
		else if (!ft_strcmp(argv[i], "--french"))
			data->french = 1;
		else if (!ft_strcmp(argv[i], "--unlimited"))
			data->unlimited = 1;
		else
			return (0);
		i++;
	}
	if (data->french == 1)
	{
		data->extra = 0;
		data->color = 0;
	}
	return (1);
}

static int	ft_initialization(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
		data->nbr = argv[1];
	else if (argc > 2)
		data->nbr = argv[2];
	if (!ft_option(data, argc, argv))
		return (0);
	return (ft_test_arg(data->nbr, data->unlimited));
}

int	main(int argc, char **argv)
{
	char		*content;
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (!ft_initialization(&data, argc, argv))
		return (ft_print_error(2, "Error\n"));
	content = ft_getcontent("numbers_en.dict", argc, argv);
	if (!content)
		return (ft_print_error(2, "Dict Error\n"));
	ft_build_list(content, &data.lst);
	ft_strdel(&content);
	if (!data.lst)
		return (ft_print_error(2, "Dict Error\n"));
	data.spoken = ft_display(data);
	if (data.spoken)
		ft_print_list(data.spoken, data.color);
	ft_list_clear(data.lst);
	if (!data.spoken)
		return (ft_print_error(2, "Dict Error\n"));
	ft_spoken_clear(data.spoken);
	return (0);
}
