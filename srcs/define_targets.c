/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_targets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:09:26 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/08 20:41:04 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_pb(t_stack **stack_a, t_stack **stack_b, t_stack **max)
{
	t_stack		*a;
	t_stack		*b;

	a = *stack_a;
	while (a)
	{
		b = *stack_b;
		while (b)
		{
			if ((b -> num < a -> num)
				&& (!(a -> target) || (b -> num > a -> target -> num)))
				a -> target = b;
			b = b -> next;
		}
		if (!a -> target)
			a -> target = *max;
		a = a -> next;
	}
}

static void	set_target_pa(t_stack **stack_a, t_stack **stack_b, t_stack **min)
{
	t_stack		*a;
	t_stack		*b;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		while (a)
		{
			if ((b -> num < a -> num)
				&& (!(b -> target) || (a -> num < b -> target -> num)))
				b -> target = a;
			a = a -> next;
		}
		if (!b -> target)
			b -> target = *min;
		b = b -> next;
	}
}

void	define_target_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*head_b;
	t_stack		*max;

	max = NULL;
	head_b = *stack_b;
	while (head_b)
	{
		if (!max || head_b -> num > max -> num)
			max = head_b;
		head_b = head_b -> next;
	}
	set_target_pb(stack_a, stack_b, &max);
}

void	define_target_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*head_a;
	t_stack		*min;

	min = NULL;
	head_a = *stack_a;
	while (head_a)
	{
		if (!min || head_a -> num < min -> num)
			min = head_a;
		head_a = head_a -> next;
	}
	set_target_pa(stack_a, stack_b, &min);
}

t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*head;
	t_stack	*cheapest;

	cheapest = NULL;
	head = *stack;
	while (head)
	{
		if (!cheapest)
			cheapest = head;
		else if ((head -> cost + head -> target -> cost)
			< (cheapest -> cost + cheapest -> target -> cost))
			cheapest = head;
		head = head -> next;
	}
	cheapest -> cheapest = 1;
	return (cheapest);
}
