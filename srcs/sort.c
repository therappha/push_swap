/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:17:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/08 19:51:29 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	while (stacklen(stack_a) > 3 && stacklen(stack_b) < 2)
		pb(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_b_to_a(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	
}

// if index of the two ;nodes are the same and are above mediam = rrr
// if index of the two nodes are the same and are below median = rr

