/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:21:02 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 18:31:13 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_one_stack(t_stack **stack_a)
{
	free_stack(stack_a);
	exit(write(2, "Error\n", 6));
}

void	free_stack_array(t_stack **stack_a, int *array)
{
	free_stack(stack_a);
	free(array);
}

void	free_every_thing(t_stack **stack_a, t_stack **stack_b, int *array)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(array);
}

void	free_stack(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*current;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		temp = current;
		current = current->next_data;
		free(temp);
	}
	*stack_a = NULL;
}
