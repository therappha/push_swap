/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:13:11 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/05 20:05:29 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *new_node(int data);
void	ft_stack_addback(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);

void	stack_init(t_stack **stack_a, int *num_array, int stack_size)
{
	t_stack *node;
	int		i;
	i = 0;
	while (i < stack_size)
	{
		node = new_node(num_array[i]);
		ft_stack_addback(stack_a, node);
		i++;
	}
}

t_stack *new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> num = data;
	node -> next = NULL;
	return (node);
}

void	ft_stack_addback(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_stacklast(*lst);
	temp -> next = new;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
