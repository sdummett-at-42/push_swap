/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_instruc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:48:10 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 23:49:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_instruc	*lstnew(char *line)
{
	t_instruc	*new;

	new = malloc(sizeof(t_instruc));
	if (new == NULL)
		return (NULL);
	new->content = line;
	new->next = NULL;
	return (new);
}

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
