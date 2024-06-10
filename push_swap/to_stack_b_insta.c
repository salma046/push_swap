/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_b_insta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:02:53 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/02 15:54:24 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **stack_b, t_stack *new)
{
	if (!stack_b || !new)
		return ;
	new->next_data = *stack_b;
	*stack_b = new;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*new;

	head_a = *stack_a;
	new = *stack_a;
	*stack_a = head_a->next_data;
	new->next_data = NULL;
	ft_lstadd_front(stack_b, new);
}

void	ra(t_stack **stack_a)
{
	t_stack	*head_a;
	t_stack	*new;

	head_a = *stack_a;
	new = *stack_a;
	*stack_a = head_a->next_data;
	new->next_data = NULL;
	ft_lstadd_back(stack_a, new);
}

void	sb(t_stack **stack_b)
{
	t_stack	*s_element;
	t_stack	*f_element;

	f_element = *stack_b;
	s_element = (*stack_b)->next_data;
	f_element->next_data = s_element->next_data;
	s_element->next_data = f_element;
	*stack_b = s_element;
}

int	do_pb_and_rb(t_stack **stack_a, t_stack **stack_b, int k)
{
	int	temp;

	temp = 0;
	if (k == 3)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
		return (temp);
	}
	pb(stack_a, stack_b);
	write(1, "pb\n", 3);
	if (k == 1)
	{
		ra(stack_b);
		write(1, "rb\n", 3);
	}
	temp = 1;
	return (temp);
}
