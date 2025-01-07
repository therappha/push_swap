/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:28:45 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 15:52:00 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	init_cost(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	int		stack_size;
	int		medium;
	int	i;

	head = *stack;
	stack_size = stack_len(stack);
	medium = stack_size / 2;

	i = 0;
	while (head && i <= medium)
	{
		head -> cost = i;
		head = head -> next;
		i++;
	}
	i = 1;
	last = ft_stacklast(*stack);
	while(last && i > medium)
	{
		last -> cost = i;
	}
}
1
2
3
4
5
6
