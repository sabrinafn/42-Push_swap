/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:20 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 11:00:42 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **source, t_list **destination)
{
	t_list	*temp_src;
	t_list	*temp_dest;
	t_list	*store_node;

	if (!*source)
		return ;
	temp_src = *source;
	temp_dest = *destination;
	store_node = temp_src -> next;
	temp_src -> next = temp_dest;
	*source = store_node;
	*destination = temp_src;
}

void	pa(t_list **source, t_list **destination)
{
	push(source, destination);
	ft_putstr(1, "pa\n");
}

void	pb(t_list **source, t_list **destination)
{
	push(source, destination);
	ft_putstr(1, "pb\n");
}
