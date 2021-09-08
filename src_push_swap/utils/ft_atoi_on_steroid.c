/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_on_steroid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 21:25:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/08 15:38:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** An ft_atoi that also checks if the number overflow/underflow an int 
*/

int	compute(const char *str, long int nb, int sign, unsigned char *overflow)
{
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

int	ft_atoi_on_steroid(const char *str, unsigned char *overflow)
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
	return (compute(str, nb, sign, overflow));
}
