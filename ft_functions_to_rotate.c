/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_to_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:22:19 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 11:35:50 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_list **a)
{
	t_list	*lst;

	lst = *a;
	set_cost_move_up(a);
	while (lst -> index != 1)
		lst = lst -> next;
	move_right_node_to_top_a(a, lst -> cost_move_up);
}

void	move_right_node_to_top_a(t_list **stack, int moves)
{
	while (moves > 0)
	{
		ra(stack);
		moves--;
	}
	while (moves < 0)
	{
		rra(stack);
		moves++;
	}
}

void	move_right_node_to_top_b(t_list **stack, int moves)
{
	while (moves > 0)
	{
		rb(stack);
		moves--;
	}
	while (moves < 0)
	{
		rrb(stack);
		moves++;
	}
}

void	move_both_to_top(t_list **a, int *mova, t_list **b, int *movb)
{
	while (*mova > 0 && *movb > 0)
	{
		rr(a, b);
		(*mova)--;
		(*movb)--;
	}
	while (*mova < 0 && *movb < 0)
	{
		rrr(a, b);
		(*mova)++;
		(*movb)++;
	}
}

void	rotate_stacks_to_position(t_list **a, t_list **b)
{
	int		index;
	int		moves_a;
	int		moves_b;
	t_list	*stack_a;
	t_list	*stack_b;

	index = get_node_index_with_lowest_total_cost(b);
	stack_a = *a;
	stack_b = *b;
	while (stack_b -> index != index)
		stack_b = stack_b -> next;
	moves_b = stack_b -> cost_move_up;
	while (stack_a -> index != stack_b -> closest_node)
		stack_a = stack_a -> next;
	moves_a = stack_a -> cost_move_up;
	move_both_to_top(a, &moves_a, b, &moves_b);
	move_right_node_to_top_b(b, moves_b);
	move_right_node_to_top_a(a, moves_a);
}
