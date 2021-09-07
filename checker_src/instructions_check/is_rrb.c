/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:50:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 01:52:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	is_rrb(t_instruc *lst, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(lst->content);
		if (len < 3)
			len = 3;
		if (ft_memcmp(lst->content, "rrb", len) == 0)
		{
			*res = 0;
			lst->instruction = RRB;
		}
	}
}
