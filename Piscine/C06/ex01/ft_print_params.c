/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:44:32 by asay              #+#    #+#             */
/*   Updated: 2025/03/10 18:45:16 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			k = 0;
			while (argv[i][k] != '\0')
			{
				write(1, &argv[i][k], 1);
				k++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
