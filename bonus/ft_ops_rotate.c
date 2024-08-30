/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:20 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 18:54:03 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*new_head;
	t_list	*last_node;

	if (*lst == NULL || (*lst)-> next == NULL)
		return ;
	temp = *lst;
	last_node = *lst;
	new_head = temp -> next;
	while (last_node -> next != NULL)
		last_node = last_node -> next;
	last_node -> next = temp;
	temp -> next = NULL;
	*lst = new_head;
}

void	ra(t_list **lst)
{
	rotate(lst);
}

void	rb(t_list **lst)
{
	rotate(lst);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
