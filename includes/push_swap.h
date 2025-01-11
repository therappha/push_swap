/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:29:17 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:08:51 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*target;
	int				cost;
	int				index;
	int				cheapest;
	int				above_median;
}	t_stack;

//debug
void	print_stacks(t_stack **stack_a, t_stack **stack_b);

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
void	sort(t_stack **stack_a, t_stack **stack_b);
void	init_stack_index(t_stack **stack_a, t_stack **stack_b);
void	init_stack_cost(t_stack **stack);
void	define_target_pb(t_stack **stack_a, t_stack **stack_b);
void	define_target_pa(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_cheapest(t_stack **stack);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);

//operations
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
#endif
