/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:17:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 15:42:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	while (stacklen(stack_a) > 3 && stacklen(stack_b) < 2)
		pb(stack_a, stack_b);

}


// target a -> b : closest smaller or max;



// target b - > a : closest bigger or min;
