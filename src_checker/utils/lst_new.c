/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:15:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/09 15:13:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Function that create a new element
*/

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
