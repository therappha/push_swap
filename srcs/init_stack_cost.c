/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:28:45 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/08 19:43:18 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_index(t_stack **stack_a, t_stack **stack_b);

void	init_stack_index(t_stack **stack_a, t_stack **stack_b)
{
	reset_index(stack_a, stack_b);
	init_stack_cost(stack_a);
	init_stack_cost(stack_b);
}

void	init_stack_cost(t_stack **stack)
{
	t_stack	*head;
	int		i;
	int		size;

	size = stacklen(stack);
	head = *stack;
	i = 0;
	while (head)
	{
		if (head -> index <= (size / 2))
		{
			head -> cost = head -> index;
			head -> above_median = 0;
		}
		else
		{
			head -> above_median = 1;
			if (size % 2 == 0)
				head->cost = head->index - (head->index - (size / 2) + ++i);
			else
				head->cost = head->index - (head->index - (size / 2) + i++);
		}
		head = head -> next;
	}
}

void	reset_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;

	head_a = *stack_a;
	head_b = *stack_b;
	i = 0;
	while (head_a)
	{
		head_a -> above_median = 0;
		head_a -> cheapest = 0;
		head_a -> index = i++;
		head_a -> target = NULL;
		head_a = head_a -> next;

	}
	i = 0;
	while (head_b)
	{
		head_b -> above_median = 0;
		head_b -> cheapest = 0;
		head_b -> index = i++;
		head_b -> target = NULL;
		head_b = head_b -> next;
	}
}
