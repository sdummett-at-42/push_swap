/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 23:09:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 00:17:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_instruc	*get_instructions(void)
{
	t_instruc	*instruc;
	char		*line;
	int			res;

	instruc = NULL;
	res = 1;
	while (res == 1)
	{
		res = get_next_line(0, &line);
		if (res == -1)
		{
			lst_clear(&instruc);
			exit(1);
		}
		if (res == 0)
			free(line);
		else
			lstadd_back(&instruc, lstnew(line));
	}
	return (instruc);
}
