/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:48:50 by asay              #+#    #+#             */
/*   Updated: 2025/03/10 05:01:38 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	rslt;

	rslt = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		rslt *= nb;
		nb--;
	}
	return (rslt);
}
