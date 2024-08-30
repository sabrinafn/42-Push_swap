/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:46:35 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 20:14:32 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	push_swap(t_list **a, t_list **b, char *ops)
{
	if (ft_strcmp(ops, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(ops, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(ops, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(ops, "pa\n") == 0)
		pa(b, a);
	else if (ft_strcmp(ops, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(ops, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(ops, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(ops, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(ops, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(ops, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(ops, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	read_and_sort(t_list **a, t_list **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (push_swap(a, b, str) == 0)
		{
			free(str);
			return (-1);
		}
		free(str);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac > 1)
	{
		if (argument_checks(ac, av))
		{
			a = store_node(ac, av);
			b = NULL;
			if (read_and_sort(&a, &b) == -1)
			{
				error();
				ft_lstclear(&a);
				return (0);
			}
			if (is_sorted(a) && b == NULL)
				ft_putstr(1, "OK\n");
			else
				ft_putstr(1, "KO\n");
			ft_lstclear(&a);
			ft_lstclear(&b);
		}
		else
			error();
	}
	return (0);
}
