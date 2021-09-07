/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:50:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 14:34:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	is_sb(t_instruc *lst, int *res)
{
	int	len;

	if (*res == 1)
	{
		len = ft_strlen(lst->content);
		if (len < 2)
			len = 2;
		if (ft_memcmp(lst->content, "sb", len) == 0)
		{
			*res = 0;
			lst->instruction = SB;
		}
	}
}
