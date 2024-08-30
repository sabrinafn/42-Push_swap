/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:22:12 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 12:28:47 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	int				index;
	int				closest_node;
	int				cost_move_up;
	int				total_cost;
}	t_list;

// FT_OPS_SWAP.C
void		swap(t_list **lst);
void		sa(t_list **lst);
void		sb(t_list **lst);
void		ss(t_list **a, t_list **b);

// FT_OPS_PUSH.C
void		push(t_list **source, t_list **destination);
void		pa(t_list **source, t_list **destination);
void		pb(t_list **source, t_list **destination);

// FT_OPS_ROTATE.C
void		rotate(t_list **lst);
void		ra(t_list **lst);
void		rb(t_list **lst);
void		rr(t_list **a, t_list **b);

// FT_OPS_REVERSE_ROTATE.C
void		reverse_rotate(t_list **lst);
void		rra(t_list **lst);
void		rrb(t_list **lst);
void		rrr(t_list **a, t_list **b);

// FT_CHECK_ARGS.C
int			ft_isdigit(int ac, char **av);
int			ft_isunique(int ac, char **av);
int			ft_isint(int ac, char **av);
int			ft_isempty(char **av);
int			argument_checks(int ac, char **av);

// FT_UTILS.C
int			ft_abs(int n);
long int	ft_atol(char *str);
void		ft_putstr(int fd, char *str);
void		error(void);

// FT_LINKED_LIST_MANAGER.C
t_list		*create_node(int data);
t_list		*store_node(int size, char **digit);
void		add_node_back(t_list **lst, t_list *new_node);
void		free_lst(t_list *node);
void		ft_lstclear(t_list **lst);

// FT_LINKED_LIST_UTILS.C
void		update_closest_digits(t_list **stack_a, t_list **stack_b);
int			ft_lstsize(t_list *lst);
int			is_sorted(t_list *lst);

// FT_CALCULATE_COST.C
void		set_cost_move_up(t_list **lst);
void		set_total_cost(t_list **a, t_list **b);
void		calculate_cost_sum(t_list **a, t_list **b);
int			get_node_index_with_lowest_total_cost(t_list **b);

// FT_SET_INDEX.C
void		sort_array(int *arr, int size);
int			*list_to_array(t_list *lst);
int			find_index(int *arr, int size, int digit);
void		set_index(t_list **lst);

// FT_CALCULATIONS.C
float		average_list(t_list *lst);
int			find_min(t_list *lst);
int			find_max(t_list *lst);

//	FT_FUNCTIONS_TO_ROTATE.C	
void		move_both_to_top(t_list **a, int *mova, t_list **b, int *movb);
void		move_right_node_to_top_a(t_list **stack, int moves);
void		move_right_node_to_top_b(t_list **stack, int moves);
void		move_min_to_top(t_list **a);
void		rotate_stacks_to_position(t_list **a, t_list **b);

// FT_SORT_SMALL.C
void		sort_two_nodes(t_list **stack);
void		sort_three_nodes(t_list **stack);
void		sort_four_nodes(t_list **a, t_list **b);
void		sort_five_nodes(t_list **a, t_list **b);
void		sort_small(t_list **a, t_list **b);

// FT_SORT.C
void		ft_sort(t_list **a, t_list **b);
void		send_to_a(t_list **a, t_list **b);
void		send_to_b(t_list **a, t_list **b);

#endif
