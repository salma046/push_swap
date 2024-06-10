/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_instra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:40:43 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 19:21:38 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	ra(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrb(stack_a);
	rrb(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sb(stack_a);
	sb(stack_b);
}

void	free_exit(char *string, t_stack **a, t_stack **b, int *array)
{
	if (string)
		free(string);
	free_every_thing(a, b, array);
	exit(write(2, "Error\n", 6));
}

void	read_from_shell(char *string, t_stack **a, t_stack **b, int *array)
{
	if (ft_strcmp(string, "sa\n") == 0)
		sb(a);
	else if (ft_strcmp(string, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(string, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(string, "rb\n") == 0)
		ra(b);
	else if (ft_strcmp(string, "pa\n") == 0)
		pb(b, a);
	else if (ft_strcmp(string, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(string, "rra\n") == 0)
		rrb(a);
	else if (ft_strcmp(string, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(string, "ss\n") == 0)
		ss(b, a);
	else if (ft_strcmp(string, "rr\n") == 0)
		rr(b, a);
	else if (ft_strcmp(string, "rrr\n") == 0)
		rrr(b, a);
	else
		free_exit(string, a, b, array);
}
