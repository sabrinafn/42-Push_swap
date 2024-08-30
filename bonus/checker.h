/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:22:12 by sabrifer          #+#    #+#             */
/*   Updated: 2024/08/28 19:18:01 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
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
void		ft_putstr(int fd, char *str);
void		error(void);

// FT_LINKED_LIST_MANAGER.C
t_list		*create_node(int data);
t_list		*store_node(int size, char **digit);
void		add_node_back(t_list **lst, t_list *new_node);
void		free_lst(t_list *node);
void		ft_lstclear(t_list **lst);

int			is_sorted(t_list *lst);
//void		move_min_to_top(t_list **a);

// FT_UTILS.C
long int	ft_atol(char *str);
void		ft_putstr(int fd, char *str);
void		error(void);

// GET_NEXT_LINE
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
