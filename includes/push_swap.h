/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:29:17 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/04 20:37:10 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_stack
{
	int num;
	struct s_stack *next;
	struct s_stack *prev;
	int index;
} t_stack;

int		*make_array(int ac, char **av);
void	stack_init(t_stack **stack_a, int *num_array, int stack_size);
int		stack_sorted(t_stack **stack);
int	ft_countwords(const char *s, char c);

#endif
