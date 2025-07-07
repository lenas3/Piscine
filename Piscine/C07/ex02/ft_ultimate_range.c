/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:33:07 by asay              #+#    #+#             */
/*   Updated: 2025/03/13 12:36:47 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	arr[i] = '\0';
	*range = arr;
	return (len);
}
