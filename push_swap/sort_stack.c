/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:15:04 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 19:01:44 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_equal(int f_element, int *array, int n, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (f_element == array[n])
			return (1);
		n++;
		i++;
	}
	return (0);
}

int	bigger_than_chunk(int f_element, int *array, int n, int j)
{
	int	l;

	l = j - 1;
	if (f_element > array[n + l])
		return (1);
	return (0);
}

int	smaller_than_chunk(int f_element, int *array, int n)
{
	if (f_element < array[n])
		return (1);
	return (0);
}

void	sorting_it(t_stack **stack_a, t_stack **stack_b, int *array, int j)
{
	t_stack	*one;
	int		n;
	int		temp;
	int		element;
	int		len;

	n = 0;
	temp = 0;
	len = get_len(stack_a);
	while (*stack_a)
	{
		one = *stack_a;
		element = one->data;
		if (temp == 1 && n < len - j)
		{
			n++;
			temp = 0;
		}
		if (is_equal(element, array, n, j) == 1)
			temp = do_pb_and_rb(stack_a, stack_b, 2);
		else if (bigger_than_chunk(element, array, n, j) == 1)
			temp = do_pb_and_rb(stack_a, stack_b, 3);
		else if (smaller_than_chunk(element, array, n) == 1)
			temp = do_pb_and_rb(stack_a, stack_b, 1);
	}
}

void	take_apropriate_range(t_stack **stack_a, t_stack **stack_b, int *array,
		int count)
{
	if (count >= 6 && count <= 15)
		sorting_it(stack_a, stack_b, array, 3);
	else if (count <= 100)
		sorting_it(stack_a, stack_b, array, 13);
	else if (count <= 500)
		sorting_it(stack_a, stack_b, array, 30);
	else
		sorting_it(stack_a, stack_b, array, 45);
}
