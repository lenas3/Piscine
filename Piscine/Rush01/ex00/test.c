#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
	}
}

void	print_grid(int grid[4][4]) //diziyi ekrana yazdırmak için 
{
	int	row; // satır numarası
	int	col; // sütun numarası
	char	c; // dizi elemanını karaktere çevirmek için kullanılır.

	row = 0;
	while (row < 4) 
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0'; // tam sayı girilen değeri karaktere çeviriyoruz
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
// sütun ve satır için girilen değerlerin geçerli olup olmadığını kontrol eden fonk.
{
	int i; 

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
            /*sudoku mantığı aslında, eğer 4*4'lük sistemde 
            bir satırda olan deger başka bir satırda, başka bir sütunda olan 
            değer başka bir sütunda olmasın kontrolü yapılıyor.*/ 
		i++;
	}
	return (1);
}



int	check_visibility(int grid[4][4], int *rules)
{
	int	row;
	int	col;
	int	max;
	int	visible;
	int	i;

	col = 0;
	while (col < 4)
	{
		max = 0;
		visible = 0;
		row = 0;
		while (row < 4)
		{
			if (grid[row][col] > max)
			{
				max = grid[row][col]; // eğer o bloktaki sayı şu ana kadar girilmiş en büyük sayı ise max'a atıyoruz.
				visible++; // görünebilen sayısı da 1 artırılır.
			}
			row++;
		}
		if (visible != rules[col]) 
        // eğer beklenen görünebilir sayı aşılmışsa (yani kurallar ihlal edilmişse) 0 döndürüyoruz. 
		    return (0);
		col++;
	}
	col = 0;
	while (col < 4)
	{
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
		col++;
	}
	row = 0;
	while (row < 4)
	{
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
		row++;
	}

	row = 0;
	while (row < 4)
	{
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
		row++;
	}

	return (1);
}

int	solve(int grid[4][4], int *rules, int row, int col)
{
	int num;

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
	int *rules;
	int i;
	int j;

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

int	main(int argc, char **argv)
{
	int grid[4][4] = {{0}};
	int *rules;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	rules = parse_input(argv[1]);
	if (!rules)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (solve(grid, rules, 0, 0))
		print_grid(grid);
	else
		ft_putstr("Error\n");

	free(rules);
	return (0);
}