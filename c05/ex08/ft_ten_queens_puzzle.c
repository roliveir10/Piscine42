/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:28:08 by roolivei          #+#    #+#             */
/*   Updated: 2021/07/09 23:01:30 by roolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static int	ft_check_queentab_validity(int queentab[10], int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (x != i && queentab[i] == y)
			return (0);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (queentab[i] != -1 && x != i
			&& ft_abs(x - i) == ft_abs(y - queentab[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_print_solution(int queentab[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = (char)(queentab[i]) + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	ft_debug_line(int y, int queentab[10])
{
	int	i;

	i = -1;
	while (++i < 10)
		printf("----");
	printf("--\n");
	i = 0;
	while (i < 10)
	{
		printf("|");
		if (queentab[i] == y)
			printf(" %d ", queentab[i]);
		else
			printf("   ");
		i++;
	}
	printf("|");
	printf("\n");
}

static void	ft_debug_queen(int queentab[10])
{
	int	j;

	j = 0;
	printf("\e[1;1H\e[2J");
	while (j < 10)
	{
		ft_debug_line(j, queentab);
		j++;
	}
	j = -1;
	while (++j < 10)
		printf("----");
	printf("--\n");
}
static int	ft_solver(int queentab[10], int x, int y, int *sol)
{
	int		j;
	int		tmp;

	j = 0;
	if (x == 10)
	{
		*sol += 1;
		ft_print_solution(queentab);
		return (1);
	}
	while (j < 10)
	{
		tmp = queentab[x];
		queentab[x] = j;
		ft_debug_queen(queentab);
		read(1, NULL, 1);
		if (ft_check_queentab_validity(queentab, x, j))
			ft_solver(queentab, x + 1, y, sol);
		queentab[x] = tmp;
		j++;
		if (j == 10)
			return (0);
	}
	return (0);
}



int	ft_ten_queens_puzzle(void)
{
	int	queentab[10];
	int	solution;
	int	i;

	i = -1;
	solution = 0;
	while (++i < 10)
		queentab[i] = -1;
	ft_solver(queentab, 0, 0, &solution);
	return (solution);
}
