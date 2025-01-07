/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:29:17 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 13:13:49 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <limits.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	num;
	struct s_stack *next;
	int	cost;
	int	index;
} t_stack;

//debug
void print_stacks(t_stack **stack_a, t_stack **stack_b);

//utils
long	*make_array(int ac, char **av);
void	stack_init(t_stack **stack_a, long *num_array, int stack_size);
int		stack_sorted(t_stack **stack);
int		ft_countwords(const char *s, char c);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_addback(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	sort_three(t_stack **stack_a);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);
int		stacklen(t_stack **stack);
void	*freesplit(char **array, int i);

//operations
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif
