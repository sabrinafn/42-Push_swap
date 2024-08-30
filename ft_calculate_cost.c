/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:45:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 11:42:09 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_move_up(t_list **lst)
{
	int		i;
	int		size;
	t_list	*stack;

	i = 0;
	size = ft_lstsize(*lst);
	stack = *lst;
	while (i < size)
	{
		if (i < size / 2)
			stack -> cost_move_up = i;
		else
			stack -> cost_move_up = -(size - i);
		stack = stack -> next;
		i++;
	}
}

void	calculate_cost_sum(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		sum;

	stack_a = *a;
	stack_b = *b;
	sum = 0;
	while (stack_b)
	{
		stack_a = *a;
		while (stack_a)
		{
			if (stack_b -> closest_node == stack_a -> index)
			{
				sum = ft_abs(stack_b -> cost_move_up);
				sum += ft_abs(stack_a -> cost_move_up);
				stack_b -> total_cost = sum;
				stack_a -> total_cost = sum;
			}
			stack_a = stack_a -> next;
		}
		stack_b = stack_b -> next;
	}
}

void	set_total_cost(t_list **a, t_list **b)
{
	set_cost_move_up(b);
	set_cost_move_up(a);
	calculate_cost_sum(a, b);
}

int	get_node_index_with_lowest_total_cost(t_list **b)
{
	int		lowest_cost;
	int		index;
	t_list	*current;

	lowest_cost = INT_MAX;
	index = 0;
	current = *b;
	while (current)
	{
		if (current -> total_cost < lowest_cost)
		{
			lowest_cost = current -> total_cost;
			index = current -> index;
		}
		current = current -> next;
	}
	return (index);
}
