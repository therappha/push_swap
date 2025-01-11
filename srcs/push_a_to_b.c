/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:52:21 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:10:03 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_r_pb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while ((*stack_a)-> next -> next -> next)
	{
		define_target_pb(stack_a, stack_b);
		cheapest = find_cheapest(stack_a);
		rotate_r_pb(stack_a, stack_b, cheapest);
		while ((*stack_a) != cheapest)
		{
			if (cheapest -> above_median)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		while ((*stack_b) != cheapest -> target)
		{
			if (cheapest -> target -> above_median)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		pb(stack_a, stack_b, 1);
		init_stack_index(stack_a, stack_b);
	}
}

void	rotate_r_pb(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_a) != cheapest && (*stack_b) != cheapest -> target)
	{
		if (cheapest -> above_median && cheapest -> target -> above_median)
			rrr(stack_a, stack_b, 1);
		else if (!cheapest -> above_median
			&& !cheapest -> target -> above_median)
			rr(stack_a, stack_b, 1);
		else
			break ;
	}
}
