/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:52:44 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:10:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_r_pa(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while ((*stack_b))
	{
		define_target_pa(stack_a, stack_b);
		cheapest = find_cheapest(stack_b);
		rotate_r_pa(stack_a, stack_b, cheapest);
		while ((*stack_b) != cheapest)
		{
			if (cheapest -> above_median)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		while ((*stack_a) != cheapest -> target)
		{
			if (cheapest -> target -> above_median)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}

void	rotate_r_pa(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_b) != cheapest && (*stack_a) != cheapest -> target)
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
