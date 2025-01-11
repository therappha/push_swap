/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:32:40 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 18:56:34 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	perform_ops(t_stack **stack_a, t_stack **stack_b, char *str);
static void	do_ops(t_stack **stack_a, t_stack **stack_b);

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
		do_ops(&stack_a, &stack_b);
		free_stacks(&stack_a, &stack_b);
	}
	return (0);
}

static void	do_ops(t_stack **stack_a, t_stack **stack_b)
{
	int		stdin;
	char	*str;

	stdin = 0;
	while (1)
	{
		str = get_next_line(stdin);
		if (str == NULL)
			break ;
		if (!perform_ops(stack_a, stack_b, str))
		{
			free(str);
			ft_printf("Error\n");
			return ;
		}
		free(str);
	}
	if (stack_sorted(stack_a) && (!*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static int	perform_ops(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}
