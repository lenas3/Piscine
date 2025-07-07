/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:47:37 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/09 19:47:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int *rules, int col)
{
	int	row;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	row = 0;
	while (row < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row++;
	}
	if (visible != rules[col])
		return (0);
	return (1);
}

int	check_col_down(int grid[4][4], int *rules, int col)
{
	int	row;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	row = 3;
	while (row >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		row--;
	}
	if (visible != rules[4 + col])
		return (0);
	return (1);
}

int	check_row_left(int grid[4][4], int *rules, int row)
{
	int	col;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	col = 0;
	while (col < 4)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col++;
	}
	if (visible != rules[8 + row])
		return (0);
	return (1);
}

int	check_row_right(int grid[4][4], int *rules, int row)
{
	int	col;
	int	max;
	int	visible;

	max = 0;
	visible = 0;
	col = 3;
	while (col >= 0)
	{
		if (grid[row][col] > max)
		{
			max = grid[row][col];
			visible++;
		}
		col--;
	}
	if (visible != rules[12 + row])
		return (0);
	return (1);
}

int	check_visibility(int grid[4][4], int *rules)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col_up(grid, rules, i))
			return (0);
		if (!check_col_down(grid, rules, i))
			return (0);
		if (!check_row_left(grid, rules, i))
			return (0);
		if (!check_row_right(grid, rules, i))
			return (0);
		i++;
	}
	return (1);
}
