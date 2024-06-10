/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_or_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:37:41 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 18:29:07 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(int *array, t_stack **stack_a)
{
	t_stack	*check;
	int		i;

	i = 0;
	check = *stack_a;
	while (check && (check->data == array[i]))
	{
		i++;
		check = check->next_data;
	}
	if (!check && !array[i])
	{
		free_stack_array(stack_a, array);
		return (1);
	}
	return (0);
}

int	ft_lstsize(t_stack **stack_b)
{
	int		i;
	t_stack	*count;

	i = 0;
	count = *stack_b;
	while (count)
	{
		count = count->next_data;
		i++;
	}
	return (i);
}

int	count_stack_elements(t_stack **stack_a)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = *stack_a;
	while (current != NULL)
	{
		count++;
		current = current->next_data;
	}
	return (count);
}

int	check_double(t_stack **stack_a)
{
	t_stack	*to_check;
	t_stack	*temp;
	int		check_double;
	int		count;

	to_check = *stack_a;
	while (to_check != NULL)
	{
		check_double = to_check->data;
		temp = *stack_a;
		while (temp != NULL)
		{
			if (check_double == temp->data && temp != to_check)
			{
				free_stack(stack_a);
				exit(write(2, "Error\n", 7));
			}
			temp = temp->next_data;
		}
		to_check = to_check->next_data;
	}
	count = count_stack_elements(stack_a);
	return (count);
}
