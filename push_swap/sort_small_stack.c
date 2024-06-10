/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:17:37 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 18:56:57 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sa(t_stack **stack_a)
{
	t_stack	*stack_copy;

	stack_copy = *stack_a;
	if (stack_copy->data > stack_copy->next_data->data)
	{
		sb(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sort_stack_of_tree(t_stack **stack_a, int *array)
{
	int		i;
	t_stack	*stack_copy;

	i = 0;
	stack_copy = *stack_a;
	while (stack_copy->data != array[2])
	{
		i++;
		stack_copy = stack_copy->next_data;
	}
	if (i == 0)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	else if (i == 1)
	{
		rrb(stack_a);
		write(1, "rra\n", 4);
	}
	check_if_sa(stack_a);
	free_stack_array(stack_a, array);
}

void	sort_stack_of_for(t_stack **stack_a, t_stack **stack_b, int *array)
{
	int	l;

	l = found_position(stack_a, array, 1, 3);
	if (l == 1)
		do_ra_until(stack_a, array, 3, 1);
	else if (l == 2)
		do_rra_until(stack_a, array, 3, 1);
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
	sort_stack_of_tree(stack_a, array);
	pb(stack_b, stack_a);
	write(1, "pa\n", 3);
	ra(stack_a);
	write(1, "ra\n", 3);
	free_stack(stack_a);
}

void	sort_stack_of_five(t_stack **stack_a, t_stack **stack_b, int *array)
{
	int	l;

	l = found_position(stack_a, array, 2, 4);
	if (l == 1)
		do_ra_until(stack_a, array, 4, 1);
	else if (l == 2)
		do_rra_until(stack_a, array, 4, 1);
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
	sort_stack_of_for(stack_a, stack_b, array);
	pb(stack_b, stack_a);
	write(1, "pa\n", 3);
	ra(stack_a);
	write(1, "ra\n", 3);
	free_stack(stack_a);
}

int	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int *array, int n)
{
	if (n == 2)
	{
		sb(stack_a);
		write(1, "sa\n", 3);
		free_stack_array(stack_a, array);
	}
	else if (n == 3)
	{
		sort_stack_of_tree(stack_a, array);
	}
	else if (n == 4)
	{
		sort_stack_of_for(stack_a, stack_b, array);
	}
	else if (n == 5)
	{
		sort_stack_of_five(stack_a, stack_b, array);
	}
	return (0);
}
