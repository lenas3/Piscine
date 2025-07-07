/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:42:36 by tgeler            #+#    #+#             */
/*   Updated: 2025/03/09 20:42:36 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	ft_putstr(char *str);
int		*parse_input(char *str);
int		solve(int grid[4][4], int *rules, int row, int col);
void	print_grid(int grid[4][4]);

int	part_of_main(char **argv_, int grid_[4][4], int *rules_)
{
	rules_ = parse_input(argv_[1]);
	if (!rules_)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (solve(grid_, rules_, 0, 0))
		print_grid(grid_);
	else
		ft_putstr("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	*rules;
	int	i;
	int	j;

	rules = NULL;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	part_of_main(argv, grid, rules);
	free(rules);
	return (0);
}
