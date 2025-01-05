/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:27:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/05 20:59:59 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack)
{
	t_stack *head;
	t_stack *temp;

	if (!*stack || !stack)
		return ;
	head = *stack;
	if (!(head -> next))
		return ;
	temp = head -> next;
	head -> next = temp -> next;
	temp -> next = head;
	*stack = temp;
}

void	sa(t_stack **stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}
void	sb(t_stack **stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_printf("ss\n");
}
