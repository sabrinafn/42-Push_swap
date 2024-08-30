/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:07:58 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 11:06:27 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst -> data = data;
	lst -> next = NULL;
	return (lst);
}

void	add_node_back(t_list **lst, t_list *new_node)
{
	t_list	*ptr;

	ptr = NULL;
	if (!*lst)
		*lst = new_node;
	else
	{
		ptr = *lst;
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new_node;
	}
}

t_list	*store_node(int size, char **digit)
{
	t_list	*lst;
	int		i;

	i = 1;
	lst = create_node(ft_atol(digit[i]));
	i++;
	while (i < size)
	{
		add_node_back(&lst, create_node(ft_atol(digit[i])));
		i++;
	}
	return (lst);
}

void	free_lst(t_list *node)
{
	if (!node)
		return ;
	free_lst(node -> next);
	free(node);
}

void	ft_lstclear(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	free_lst(*lst);
	*lst = NULL;
}
