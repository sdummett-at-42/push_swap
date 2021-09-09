/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:10:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Function that add a new element at the end of a linked list or create 
** the first element if *alst is NULL
*/

void	lstadd_back(t_instruc **alst, t_instruc *new)
{
	t_instruc	*lst;

	if (!*alst)
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
