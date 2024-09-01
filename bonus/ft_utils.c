/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:30:18 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 19:15:45 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long int	ft_atol(char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	error(void)
{
	ft_putstr(2, "Error\n");
}

int	is_sorted(t_list *lst)
{
	if (!lst) // delete after maybe
		return (-1); // delete after maybe 
	while (lst -> next != NULL)
	{
		if (lst -> data > lst -> next -> data)
			return (0);
		lst = lst -> next;
	}
	return (1);
}
