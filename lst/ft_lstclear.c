/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:19:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/20 18:19:55 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (*lst)
	{
		curr = *lst;
		while (curr)
		{
			tmp = curr->next;
			(*del)(curr->content);
			free(curr);
			curr = tmp;
		}
	}
	*lst = 0;
}
