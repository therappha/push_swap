/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:13:11 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 15:55:13 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int data);
void	ft_stack_addback(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);

void	stack_init(t_stack **stack_a, long *num_array, int stack_size)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (i < stack_size)
	{
		node = new_node(num_array[i]);
		ft_stack_addback(stack_a, node);
		i++;
	}
	free(num_array);
}

t_stack	*new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> num = data;
	node -> next = NULL;
	return (node);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)-> next;
		free(*stack);
		*stack = temp;
	}
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && stack_a)
		stack_clear(stack_a);
	if (*stack_b && stack_b)
		stack_clear(stack_b);
	*stack_a = NULL;
	*stack_b = NULL;
}
