/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:50:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 14:35:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	is_rra(t_instruc *lst, int *res)
{
	int	len;

	if (*res == 1)
	{
		len = ft_strlen(lst->content);
		if (len < 3)
			len = 3;
		if (ft_memcmp(lst->content, "rra", len) == 0)
		{
			*res = 0;
			lst->instruction = RRA;
		}
	}
}
