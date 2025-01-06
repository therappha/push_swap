/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:29:17 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/06 18:22:45 by rafaelfe         ###   ########.fr       */
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
void	print_stacks(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

//utils
int		*make_array(int ac, char **av);
void	stack_init(t_stack **stack_a, int *num_array, int stack_size);
int		stack_sorted(t_stack **stack);
int		ft_countwords(const char *s, char c);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_addback(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);

//operations
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif
