/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:34:02 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 10:13:43 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isint(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1] != '\0')
			j++;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isempty(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isunique(int ac, char **av)
{
	t_list	*lst;
	t_list	*stack;
	t_list	*current;

	lst = store_node(ac, av);
	stack = lst;
	current = lst;
	while (stack)
	{
		current = stack -> next;
		while (current)
		{
			if (current -> data == stack -> data)
			{
				ft_lstclear(&lst);
				return (0);
			}
			current = current -> next;
		}
		stack = stack -> next;
	}
	ft_lstclear(&lst);
	return (1);
}

int	argument_checks(int ac, char **av)
{
	if (!ft_isdigit(ac, av))
		return (0);
	if (!ft_isunique(ac, av))
		return (0);
	if (!ft_isint(ac, av))
		return (0);
	if (!ft_isempty(av))
		return (0);
	return (1);
}
