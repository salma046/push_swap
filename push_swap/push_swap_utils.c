/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:27:15 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 18:39:11 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_before_sign(t_stack **stack_a, const char *str, int *i)
{
	int	sign;

	sign = 1;
	if ((str[*i] == '+' || str[*i] == '-'))
	{
		if (!(str[*i - 1] < '0' || str[*i - 1] > '9'))
		{
			free_stack(stack_a);
			exit(write(2, "Error\n", 6));
		}
		else if (str[*i] == '-')
			sign = -1;
		if (str[*i + 1] < '0' || str[*i + 1] > '9')
		{
			free_stack(stack_a);
			exit(write(2, "Error\n", 6));
		}
		(*i)++;
	}
	return (sign);
}

void	ft_lstadd_back(t_stack **stack_a, t_stack *new)
{
	t_stack	*all_data;

	all_data = *stack_a;
	if (!stack_a || !new)
	{
		free_stack(stack_a);
		exit(write(2, "Error\n", 6));
	}
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return ;
	}
	while (all_data->next_data != NULL)
		all_data = all_data->next_data;
	all_data->next_data = new;
}

void	fill_stack_a(t_stack **stack_a, long result, const char *str, int i)
{
	t_stack	*new;

	if (str[i] == '\0' && result == 0 && !(str[i - 1] >= '0'
			&& str[i - 1] <= '9'))
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = result;
	new->next_data = NULL;
	ft_lstadd_back(stack_a, new);
	return ;
}

long	get_result(int sign, const char *str, int *i)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
			return (result);
		(*i)++;
	}
	return (result);
}

void	ft_atoi(t_stack **stack_a, const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	while (str[i])
	{
		sign = 1;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] && !(str[i] >= '0' && str[i] <= '9') && str[i] != '+'
			&& str[i] != '-')
		{
			free_stack(stack_a);
			exit(write(2, "Error\n", 6));
		}
		sign = check_before_sign(stack_a, str, &i);
		result = get_result(sign, str, &i);
		if (result * sign < INT_MIN || result * sign > INT_MAX)
		{
			free_stack(stack_a);
			exit(write(2, "Error\n", 6));
		}
		fill_stack_a(stack_a, result * sign, str, i);
	}
}
