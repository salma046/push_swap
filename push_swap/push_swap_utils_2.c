/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:14:44 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/02 15:54:09 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_position(t_stack **stack_a, int *array, int demi_size, int n)
{
	int		l;
	int		k;
	t_stack	*head_b;

	k = 0;
	head_b = *stack_a;
	while (array[n] != head_b->data)
	{
		head_b = head_b->next_data;
		k++;
	}
	l = 0;
	if (k <= demi_size)
		l = 1;
	else if (k > demi_size)
		l = 2;
	return (l);
}

int	get_len(t_stack **stack_a)
{
	t_stack	*size;
	int		len;

	size = *stack_a;
	len = size->count;
	return (len);
}
