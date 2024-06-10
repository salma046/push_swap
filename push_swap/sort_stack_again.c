/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_again.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:55:13 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 19:05:36 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gett_lst_last(t_stack **stack_a)
{
	t_stack	*all_data;

	all_data = *stack_a;
	if (!stack_a)
		exit(write(2, "Error\n", 6));
	while (all_data->next_data != NULL)
		all_data = all_data->next_data;
	return (all_data->data);
}

int	found_half(int count)
{
	int	demi_size;

	demi_size = 0;
	if (count % 2 == 0)
		demi_size = count / 2;
	else
		demi_size = (count + 1) / 2;
	return (demi_size);
}

void	sorting_it_again(t_stack **a, t_stack **b, int *array, int count)
{
	t_stack	*head_b;
	int		l;
	int		c;

	c = count - 1;
	while (*b)
	{
		head_b = *b;
		if (c > 0 && (array[c] != head_b->data))
		{
			l = found_position(b, array, found_half(c), c);
			if (l == 1)
				do_ra_until(b, array, c, 2);
			else if (l == 2)
				do_rra_until(b, array, c, 2);
			head_b = *b;
		}
		c--;
		pb(b, a);
		write(1, "pa\n", 3);
	}
}
