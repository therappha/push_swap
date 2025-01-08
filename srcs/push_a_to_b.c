/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:52:21 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/08 19:55:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (stacklen(stack_a) > 3)
	{
		define_target_pb(stack_a, stack_b);
		cheapest = find_cheapest(stack_a);
		while ((*stack_a) != cheapest && (*stack_b) != cheapest -> target)
		{
			if (cheapest -> above_median && cheapest -> target -> above_median)
				rrr(stack_a, stack_b);
			else if (!cheapest -> above_median
				&& !cheapest -> target -> above_median)
				rr(stack_a, stack_b);
			else
				break;
		}
		while ((*stack_a) != cheapest)
		{
			if (cheapest -> above_median)
				rra(stack_a);
			else
				ra(stack_a);
		}
		while ((*stack_b) != cheapest -> target)
		{
			if (cheapest -> target -> above_median)
				rrb(stack_b);
			else
				rb(stack_b);
		}
		pb(stack_a, stack_b);
	}
}
