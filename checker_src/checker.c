/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:23:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/07 00:42:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	args_are_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
sa | sb | ss | pa | pb | ra | rb | rr | rra | rrb | rrr
*/

void	is_sa(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "sa", len) == 0)
			*res = 0;
	}
}

void	is_sb(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "sb", len) == 0)
		*res = 0;
	}
}

void	is_ss(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "ss", len) == 0)
			*res = 0;
	}
}

void	is_pa(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "pa", len) == 0)
			*res = 0;
	}
}

void	is_pb(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "pb", len) == 0)
			*res = 0;
	}
}

void	is_ra(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "ra", len) == 0)
			*res = 0;
	}
}

void	is_rb(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "rb", len) == 0)
			*res = 0;
	}
}

void	is_rr(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 2)
			len = 2;
		if (ft_memcmp(str, "rr", len) == 0)
			*res = 0;
	}
}

void	is_rra(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 3)
			len = 3; 
		if (ft_memcmp(str, "rra", len) == 0)
			*res = 0;
	}
}

void	is_rrb(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 3)
			len = 3;
		if (ft_memcmp(str, "rrb", len) == 0)
			*res = 0;
	}
}

void	is_rrr(char *str, int *res)
{
	int	len;
	
	if (*res == 1)
	{
		len = ft_strlen(str);
		if (len < 3)
			len = 3;
		if (ft_memcmp(str, "rrr", len) == 0)
			*res = 0;
	}
}


int	are_valid_instructions(t_instruc *lst)
{
	int res;

	while (lst)
	{
		res = 1;
		is_sa(lst->content, &res);
		is_sb(lst->content, &res);
		is_ss(lst->content, &res);
		is_pa(lst->content, &res);
		is_pb(lst->content, &res);
		is_ra(lst->content, &res);
		is_rb(lst->content, &res);
		is_rr(lst->content, &res);
		is_rra(lst->content, &res);
		is_rrb(lst->content, &res);
		is_rrr(lst->content, &res);
		if (res == 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_instruc	*instruc;

	if (ac < 2)
		return (0);
	if (args_are_numbers(ac, av) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stacks = create_stacks(ac);
	if (init_stacks(stacks, ac, av) < 0 || ac < 2)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 2);
	}
	if (has_duplicates(stacks) == 1)
	{
		write(2, "Error\n", 6);
		clean_exit(stacks, 3);
	}
	instruc = get_instructions();
	// t_instruc	*curr;
	// curr = instruc;
	// while (curr != NULL)
	// {
	// 	printf("%s\n", curr->content);
	// 	curr = curr->next;
	// }
	if (are_valid_instructions(instruc) == 1)
		printf("Nice instructions\n");
	else
		printf("Instructions are bad\n");
	print_stacks(stacks);
	lst_clear(&instruc);
	clean_exit(stacks, 0);
	return (0);
}
