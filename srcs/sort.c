/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:17:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 15:56:44 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_min(t_stack **stack_a);

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	while (stacklen(stack_a) > 3 && stacklen(stack_b) < 2)
		pb(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_b_to_a(stack_a, stack_b);
	if (!stack_sorted(stack_a))
		push_min(stack_a);
}

void	push_min(t_stack **stack_a)
{
	t_stack	*head_a;
	t_stack	*min;

	head_a = *stack_a;
	while (head_a)
	{
		if (!min || head_a -> num < min -> num)
			min = head_a;
		head_a = head_a -> next;
	}
	if (min -> above_median)
	{
		while ((*stack_a) != min)
			rra(stack_a);
	}
	else
	{
		while ((*stack_a) != min)
			ra(stack_a);
	}
}
