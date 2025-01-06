/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:24:26 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/06 22:22:28 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(t_stack **stack)
{
	t_stack *head;

	head = *stack;
	while (head -> next)
	{
		if ((head -> num) > (head -> next -> num))
			return (0);
		head = head -> next;
	}
	return (1);
}


