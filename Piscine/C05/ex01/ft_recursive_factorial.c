/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:45:55 by asay              #+#    #+#             */
/*   Updated: 2025/03/11 21:36:48 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{	
	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}
