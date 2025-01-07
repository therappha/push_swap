/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:21:33 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 16:54:15 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (stack_sorted(stack_a))
		return ;
	if (!(*stack_a)-> next -> next)
		sa(stack_a);
	else
	{
		if ((*stack_a)-> num > (*stack_a)-> next -> num
			&& (*stack_a)-> num > (*stack_a)-> next -> next -> num)
			ra(stack_a);
		else if ((*stack_a)-> num < (*stack_a)-> next -> num
			&& (*stack_a)-> next -> num > (*stack_a)-> next -> next -> num)
			rra(stack_a);
		if ((*stack_a)-> num > (*stack_a)-> next -> num)
			sa(stack_a);
	}
}
