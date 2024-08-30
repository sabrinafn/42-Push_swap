/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:44:14 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 12:10:22 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	average_list(t_list *lst)
{
	t_list	*stack;
	float	sum;
	int		size;

	sum = 0;
	size = ft_lstsize(lst);
	stack = lst;
	while (stack)
	{
		sum += stack -> index;
		stack = stack -> next;
	}
	sum = sum / size;
	return (sum);
}

int	find_min(t_list *lst)
{
	t_list	*stack;
	int		min;

	stack = lst;
	min = stack -> index;
	while (stack)
	{
		if (min > stack -> index)
			min = stack -> index;
		stack = stack -> next;
	}
	return (min);
}

int	find_max(t_list *lst)
{
	int		max;
	t_list	*stack;

	stack = lst;
	max = stack -> index;
	while (stack)
	{
		if (max < stack -> index)
			max = stack -> index;
		stack = stack -> next;
	}
	return (max);
}
