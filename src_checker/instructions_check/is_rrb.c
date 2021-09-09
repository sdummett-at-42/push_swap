/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:50:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:06:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** This function checks if the element has the "rrb" instruction well formated
** and then store the value for this instruction into the `instruction` field
*/

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
