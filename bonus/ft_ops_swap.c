/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:32:20 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 18:53:46 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **lst)
{
	t_list	*new_lst;
	t_list	*temp_lst;

	if (*lst == NULL || (*lst)-> next == NULL)
		return ;
	new_lst = *lst;
	temp_lst = *lst;
	if (new_lst -> next == NULL)
		return ;
	temp_lst = new_lst -> next;
	new_lst -> next = new_lst -> next -> next;
	temp_lst -> next = new_lst;
	*lst = temp_lst;
}

void	sa(t_list **lst)
{
	swap(lst);
}

void	sb(t_list **lst)
{
	swap(lst);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
