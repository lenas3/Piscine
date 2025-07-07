/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:30 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/09 19:26:30 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_visibility(int grid[4][4], int *rules);
void	ft_putstr(char *str);
int		*parse_input(char *str);

void	print_grid(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int *rules, int row, int col)
{
	int	num;

	if (row == 4)
		return (check_visibility(grid, rules));
	if (col == 4)
		return (solve(grid, rules, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, rules, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	*parse_input(char *str)
{
	int	*rules;
	int	i;
	int	j;

	rules = (int *)malloc(16 * sizeof(int));
	if (!rules)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			rules[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	if (j != 16)
	{
		free(rules);
		return (NULL);
	}
	return (rules);
}
