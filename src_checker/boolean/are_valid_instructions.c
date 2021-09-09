/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_valid_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:59:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 14:01:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** It checks if the instructions received on stdin are well formatted or not
*/

bool	are_valid_instructions(t_instruc *lst)
{
	int	res;

	while (lst != NULL)
	{
		res = 1;
		is_sa(lst, &res);
		is_sb(lst, &res);
		is_ss(lst, &res);
		is_pa(lst, &res);
		is_pb(lst, &res);
		is_ra(lst, &res);
		is_rb(lst, &res);
		is_rr(lst, &res);
		is_rra(lst, &res);
		is_rrb(lst, &res);
		is_rrr(lst, &res);
		if (res == 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}
