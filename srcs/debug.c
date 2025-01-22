/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:11:53 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/22 13:07:21 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Debug function made to print stacks!
void	print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*sa;
	t_stack	*sb;

	sa = *stack_a;
	sb = *stack_b;
	while (sa || sb)
	{
		ft_printf("stack_a: ");
		while (sa)
		{
			ft_printf("%d ", sa -> num);
			sa = sa -> next;
		}
		ft_printf("\nstack_b: ");
		while (sb)
		{
			ft_printf("%d ", sb -> num);
			sb = sb -> next;
		}
		ft_printf("\n");
	}
}
