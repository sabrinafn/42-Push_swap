/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:45:45 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 12:28:24 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) > 0)
	{
		update_closest_digits(a, b);
		set_total_cost(a, b);
		rotate_stacks_to_position(a, b);
		pa(b, a);
	}
}

void	send_to_b(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 5)
	{
		if ((*a)-> index < average_list(*a))
			pb(a, b);
		else
			ra(a);
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) <= 5)
	{
		sort_small(a, b);
		return ;
	}
	send_to_b(a, b);
	sort_small(a, b);
	send_to_a(a, b);
	if (!is_sorted(*a))
		move_min_to_top(a);
}
