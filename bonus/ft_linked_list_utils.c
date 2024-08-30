/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:08:18 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 19:14:31 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (lst -> data > lst -> next -> data)
			return (0);
		lst = lst -> next;
	}
	return (1);
}
