/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:25:02 by asay              #+#    #+#             */
/*   Updated: 2025/03/13 12:50:53 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_all_len(int size, char **strs, char *sep)
{
	int		i;
	int		all_len;

	all_len = 0;
	i = 0;
	while (i < size)
	{
		all_len += ft_strlen(strs[i]);
		i++;
	}	
	all_len += ft_strlen(sep) * (size - 1) + 1;
	return (all_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	i = 0;
	if (size == 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * ft_all_len(size, strs, sep));
	if (!result)
		return (NULL);
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
