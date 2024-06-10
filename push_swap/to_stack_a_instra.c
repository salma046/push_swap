/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_a_instra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:26:56 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/02 15:54:22 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **stack_b)
{
	t_stack	*last_data;
	t_stack	*the_new_head;

	if (!stack_b)
		exit(write(2, "Error\n", 6));
	last_data = *stack_b;
	while (last_data->next_data->next_data != NULL)
		last_data = last_data->next_data;
	the_new_head = last_data->next_data;
	last_data->next_data = NULL;
	the_new_head->next_data = *stack_b;
	*stack_b = the_new_head;
}

void	do_ra_until(t_stack **stack_a, int *array, int n, int k)
{
	int		num;
	t_stack	*one_stack;

	one_stack = *stack_a;
	num = one_stack->data;
	while (num != array[n])
	{
		ra(stack_a);
		if (k == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		one_stack = *stack_a;
		num = one_stack->data;
	}
}

void	do_rra_until(t_stack **stack_a, int *array, int n, int k)
{
	int		num;
	t_stack	*one_stack;

	one_stack = *stack_a;
	num = one_stack->data;
	while (num != array[n])
	{
		rrb(stack_a);
		if (k == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		one_stack = *stack_a;
		num = one_stack->data;
	}
}
