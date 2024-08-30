/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:44:32 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/26 17:25:02 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*list_to_array(t_list *lst)
{
	int		i;
	int		size;
	int		*arr;
	t_list	*stack;

	i = 0;
	size = ft_lstsize(lst);
	stack = lst;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack -> data;
		stack = stack -> next;
		i++;
	}
	sort_array(arr, size);
	return (arr);
}

int	find_index(int *arr, int size, int digit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == digit)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	set_index(t_list **lst)
{
	t_list	*stack;
	int		*arr;
	int		size;

	stack = *lst;
	arr = list_to_array((*lst));
	size = ft_lstsize(*lst);
	while (stack)
	{
		if (find_index(arr, size, stack -> data) > -1)
			stack -> index = find_index(arr, size, stack -> data);
		stack = stack -> next;
	}
	free(arr);
}
