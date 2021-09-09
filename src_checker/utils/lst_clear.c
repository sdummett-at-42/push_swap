/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:08:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:13:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Function that clear a linked list
*/

void	lst_clear(t_instruc **lst)
{
	t_instruc	*curr;
	t_instruc	*tmp;

	if (*lst)
	{
		curr = *lst;
		while (curr)
		{
			tmp = curr->next;
			free(curr->content);
			free(curr);
			curr = tmp;
		}
	}
	*lst = NULL;
}
