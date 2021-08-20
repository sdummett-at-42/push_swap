/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:25:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/20 16:31:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, unsigned char *overflow)
{
	int			sign;
	long int	nb;

	nb = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
		if (sign < 0 && nb > 2147483648)
		{
			*overflow = 1;
			return (0);
		}
		if (sign > 0 && nb > 2147483647)
		{
			*overflow = 1;
			return (-1);
		}
	}
	return (nb * sign);
}
