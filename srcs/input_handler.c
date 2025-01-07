/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:57:50 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:14 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_dup(long *num_array, int i);
int		checknum(char *str);
long	*atol_array(int i, char **array);
long	ft_atol(const char *str);

long	*make_array(int ac, char **av)
{
	char	**char_array;
	long		*num_array;
	int		i;

	num_array = NULL;
	i = 0;

	if (ac == 2)
		char_array = ft_split(av[1], ' ');
	else
		char_array = av + 1;
	i = 0;
	while (char_array[i] != NULL)
		i++;
	num_array = atol_array(i, char_array);
	if (check_dup(num_array, i))
	{
		if (ac == 2)
			return (free(num_array), freesplit(char_array, i), ft_printf("Error"), NULL);
		else
			return (free(num_array), ft_printf("Error"), NULL);
	}
	if (ac == 2)
		freesplit(char_array, i);
	return (num_array);
}

long	*atol_array(int i, char **array)
{
	long	*n_array;
	int	j;

	j = 0;
	n_array = (long *)malloc(i * sizeof(long));
		while(j < i)
		{
			if (checknum(array[j]))
				n_array[j] = ft_atol(array[j]);
			else
			{
				return(free(n_array), ft_printf("Error!"), NULL);
			}
			j++;
		}
	return (n_array);
}

int	checknum(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
			i++;
		if (!ft_isdigit(str[i]) && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
int	check_dup(long *num_array, int i)
{
	int	j;
	int	k;

	if (!num_array)
		return (0);
	j = 0;
	while (j < i)
	{
		k = 0;
		if (!(num_array[j] < INT_MAX && num_array[j] > INT_MIN))
				return (1);
		while (k < i)
		{
			if (num_array[j] == num_array[k] && j != k)
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long		minus;
	long	result;

	minus = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * minus);
}
