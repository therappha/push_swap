/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:11:53 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 13:12:08 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*sa;
	t_stack	*sb;

	sa = *stack_a;
	sb = *stack_b;
	ft_printf("\n|----------\n");
	while (sa || sb)
		{
			if (sa)
			{
				ft_printf("| %d	", sa -> num);
				sa = sa -> next;
			}
			else
				ft_printf("|   ");
			if (sb)
			{
				ft_printf("%d", sb -> num);
				sb = sb -> next;

			}
			ft_printf("\n");

		}
		ft_printf("| -	-\n| a	b\n|----------\n");
	}
