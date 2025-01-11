/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:44:44 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:09:44 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;
	t_stack	*before_last;

	head = *stack;
	if (!head || !head -> next)
		return ;
	before_last = *stack;
	while (before_last -> next -> next)
		before_last = before_last-> next;
	temp = ft_stacklast(*stack);
	ft_stackadd_front(stack, temp);
	if ((*stack)-> next -> next)
		before_last -> next = NULL;
	temp -> next = head;
	*stack = temp;
}

void	rra(t_stack **stack_a, int print)
{
	rev_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int print)
{
	rev_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
