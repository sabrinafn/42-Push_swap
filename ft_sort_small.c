/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:50:37 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/26 18:16:08 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nodes(t_list **a, t_list **b)
{
	int	max;

	max = find_max(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)-> next -> index == max)
		ra(a);
	else if ((*a)-> next -> next -> index == max)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)-> next -> next -> next -> index == max)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)-> next -> next -> next -> next -> index == max)
		rra(a);
	pb(a, b);
	sort_four_nodes(a, b);
	pa(b, a);
	ra(a);
}

void	sort_four_nodes(t_list **a, t_list **b)
{
	int	min;

	min = find_min(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)-> next -> index == min)
		ra(a);
	else if ((*a)-> next -> next -> index == min)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)-> next -> next -> next -> index == min)
		rra(a);
	pb(a, b);
	sort_three_nodes(a);
	pa(b, a);
}

void	sort_three_nodes(t_list **stack)
{
	int	max;

	max = find_max(*stack);
	if (is_sorted(*stack))
		return ;
	if ((*stack)-> index == max)
		ra(stack);
	else if ((*stack)-> next -> index == max)
		rra(stack);
	sort_two_nodes(stack);
}

void	sort_two_nodes(t_list **stack)
{
	if (is_sorted(*stack))
		return ;
	sa(stack);
}

void	sort_small(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sort_two_nodes(a);
	else if (size == 3)
		sort_three_nodes(a);
	else if (size == 4)
		sort_four_nodes(a, b);
	else if (size == 5)
		sort_five_nodes(a, b);
}
