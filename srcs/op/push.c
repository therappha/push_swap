/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:56:50 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:04:53 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	push(t_stack **origin, t_stack **dest)
{
	t_stack	*head;

	if (!origin || !*origin)
		return (0);
	head = *origin;
	(*origin) = (*origin)-> next;
	ft_stackadd_front(dest, head);
	return (1);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	push(stack_b, stack_a);
	init_stack_index(stack_a, stack_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	push(stack_a, stack_b);
	init_stack_index(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}
