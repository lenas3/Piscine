/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:52:20 by asay              #+#    #+#             */
/*   Updated: 2025/03/13 12:25:58 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	len;

	i = 0;
	len = max - min;
	arr = malloc(sizeof(int) * (len + 1));
	if (min >= max || !arr)
	{
		arr = NULL;
		return (0);
	}
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
