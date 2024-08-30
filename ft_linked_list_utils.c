/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:08:18 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 11:26:24 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_closest_digits(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;
	int		closest;

	current_a = *stack_a;
	current_b = *stack_b;
	while (current_b)
	{
		current_a = *stack_a;
		closest = INT_MAX;
		while (current_a)
		{
			if (current_a -> index < closest
				&& current_a -> index > current_b -> index)
			{
				closest = current_a -> index;
				current_b -> closest_node = closest;
			}
			current_a = current_a -> next;
		}
		current_b = current_b -> next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

int	is_sorted(t_list *lst)
{
	while (lst -> next != NULL)
	{
		if (lst -> index > lst -> next -> index)
			return (0);
		lst = lst -> next;
	}
	return (1);
}
