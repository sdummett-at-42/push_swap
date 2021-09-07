/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/06 23:11:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_data	*fd_handler(t_fd_data **fd_data, int fd)
{
	t_fd_data	*curr;

	if (*fd_data == NULL)
	{
		return (new_elem(fd_data, fd));
	}
	else
	{
		curr = *fd_data;
		while (curr->fd != fd && curr->next != NULL)
			curr = curr->next;
		if (curr->fd != fd)
			return (new_elem(fd_data, fd));
		else
			return (curr);
	}
	return (NULL);
}

char	*schr_or_mset(const char *str, int ch, size_t n, int choice)
{
	if (choice == 1)
	{
		while (*str)
		{
			if (*str == (unsigned char)ch)
				return ((char *)str);
			str++;
		}
		if (*str == (unsigned char)ch)
			return ((char *)str);
		return (0);
	}
	while (n)
	{
		*((unsigned char *)str + n - 1) = (unsigned char)ch;
		n--;
	}
	return ((char *)str);
}

int	ft_strlen_nl_or_strcpy(char *buffer, char *src, int choice)
{
	int	len;

	len = 0;
	if (choice == 1)
	{
		while (buffer[len] != '\n' && buffer[len] != '\0')
			len++;
	}
	else if (choice == 2)
	{
		while (buffer[len] != '\0')
			len++;
	}
	else if (choice == 3)
	{
		while (src[len] != '\0')
		{
			buffer[len] = src[len];
			len++;
		}
		buffer[len] = '\0';
		return (0);
	}
	return (len);
}

char	*s_buf(char *ptr, char *buffer)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen_nl_or_strcpy(buffer \
					, NULL, 2) + 1));
	if (!tmp)
		return (NULL);
	schr_or_mset(tmp, 0, ft_strlen_nl_or_strcpy(buffer, NULL, 2) \
			+ 1, 2);
	i = 0;
	while (buffer[i] != '\0')
	{
		tmp[i] = buffer[i];
		i++;
	}
	tmp[i] = '\0';
	free(ptr);
	return (tmp);
}

void	free_elem_and_relink(t_fd_data **fd_data, int fd)
{
	t_fd_data	*previous;
	t_fd_data	*elem;

	previous = NULL;
	elem = *fd_data;
	while (elem->fd != fd && elem->next != NULL)
	{
		previous = elem;
		elem = elem->next;
	}
	if (previous == NULL)
	{
		if (elem->next != NULL)
			*fd_data = elem->next;
		else
			*fd_data = NULL;
	}
	else
		previous->next = elem->next;
	free(elem);
}
