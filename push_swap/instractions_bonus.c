/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:02:53 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/02 15:53:31 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	if (ft_lstsize(stack_a) > 0)
	{
		head_a = *stack_a;
		new = *stack_a;
		*stack_a = head_a->next_data;
		new->next_data = NULL;
		ft_lstadd_front(stack_b, new);
	}
}

void	ra(t_stack **stack_a)
{
	t_stack	*head_a;
	t_stack	*new;

	if (ft_lstsize(stack_a) > 0)
	{
		head_a = *stack_a;
		new = *stack_a;
		*stack_a = head_a->next_data;
		new->next_data = NULL;
		ft_lstadd_back(stack_a, new);
	}
}

void	sb(t_stack **stack_b)
{
	t_stack	*s_element;
	t_stack	*f_element;

	if (ft_lstsize(stack_b) > 1)
	{
		f_element = *stack_b;
		s_element = (*stack_b)->next_data;
		f_element->next_data = s_element->next_data;
		s_element->next_data = f_element;
		*stack_b = s_element;
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last_data;
	t_stack	*the_new_head;

	if (ft_lstsize(stack_b) > 1)
	{
		last_data = *stack_b;
		while (last_data->next_data->next_data != NULL)
			last_data = last_data->next_data;
		the_new_head = last_data->next_data;
		last_data->next_data = NULL;
		the_new_head->next_data = *stack_b;
		*stack_b = the_new_head;
	}
}
