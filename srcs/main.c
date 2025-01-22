/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:23:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/22 13:20:35 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_countwords(const char *s, char c);

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
		if (!stack_sorted(&stack_a))
		{
			if (ac - 1 <= 3)
				sort_three(&stack_a);
			else
				sort(&stack_a, &stack_b);
		}
		free_stacks(&stack_a, &stack_b);
	}
	return (0);
}

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}
