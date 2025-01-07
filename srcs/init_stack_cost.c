/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:28:45 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 19:19:05 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	init_stack_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;

	head_a = *stack_a;
	head_b = *stack_b;
	i = 0;
	while (head_a)
	{
		head_a -> index = i;
		head_a = head_a -> next;
		i++;
	}
	i = 0;
	while (head_b)
	{
		head_b -> index = i;
		head_b = head_b -> next;
		i++;
	}
	init_stack_cost(stack_a);
	init_stack_cost(stack_b);
}

void	init_stack_cost(t_stack **stack)
{
	t_stack	*head;

	int		i;
	int		medium;
	int		stack_size;

	stack_size = stacklen(stack);
	medium = stack_size / 2;

	head = *stack;
	i = 0;
	while (head)
	{
		if (head -> index <= medium)
			head -> cost = head -> index;
		else
		{
			if (stack_size % 2 == 0)
				head -> cost = head -> index - (head -> index - medium + ++i);
			else
				head -> cost = head -> index - (head -> index - medium + i++);
		}
		head = head -> next;
	}
}

void	define_target_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*head_a;
	t_stack		*head_b;
	t_stack		*max;

	max = NULL;
	head_a = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		if (!max || head_b -> num > max -> num)
			max = head_b;
		head_b = head_b -> next;
	}
	while (head_a)
	{
		head_b = *stack_b;
		while (head_b)
		{
			if (head_b -> num < head_a -> num && (!(head_a -> target) || (head_b -> num > head_a -> target -> num)))
				head_a -> target = head_b;
			else
				head_a -> target = max;
			head_b = head_b -> next;
		}
		head_a = head_a -> next;
	}
}


// target a -> b : closest smaller or max;

