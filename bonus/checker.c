/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:32:40 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:20:28 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	long		*num_array;

	stack_a = NULL;
	stack_b = NULL;
	num_array = NULL;
	if (ac >= 2)
		num_array = make_array(ac, av);
	if (ac == 2)
		ac = ft_countwords(av[1], ' ') + 1;
	if (num_array)
	{
		stack_init(&stack_a, num_array, ac -1);
		get_ops(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
	}
	return (0);
}

