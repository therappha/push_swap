/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:23:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/05 20:59:26 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*num_array;

	stack_a = NULL;
	stack_b = NULL;
	num_array = make_array(ac, av);
	if (ac == 2)
		ac = ft_countwords(av[1], ' ') + 1;
	if (num_array)
	{
		stack_init(&stack_a, num_array, ac -1);
		if (!stack_sorted(&stack_a))
		{
			if (ac - 1 <= 3)
				ft_printf("\nsort_three(&stack_a)\n");
			else
				ft_printf("\nsort(&stack_a, &stack_b)\n");
			sa(&stack_a, 1);
			print_stacks(&stack_a);
		}
	}
	//free_stacks(&stack_a, &stack_b) and num array!!!;
	return (0);
 }
