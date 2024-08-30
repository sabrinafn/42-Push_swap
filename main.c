/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:58:54 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 12:28:11 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac > 1)
	{
		if (argument_checks(ac, av))
		{
			a = store_node(ac, av);
			b = NULL;
			set_index(&a);
			ft_sort(&a, &b);
			ft_lstclear(&a);
		}
		else
			error();
	}
	return (0);
}
