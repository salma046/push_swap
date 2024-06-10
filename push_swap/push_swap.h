/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:38:08 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/05 11:53:41 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				count;
	struct s_stack	*next_data;
}	t_stack;

void	ft_atoi(t_stack **stack_a, const char *str);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new);
void	sorting_it_again(t_stack **stack_a, t_stack **b, int *array, int count);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	sb(t_stack **stack_b);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new);
void	do_ra_until(t_stack **stack_a, int *array, int n, int k);
void	do_rra_until(t_stack **stack_a, int *array, int n, int k);
void	take_apropriate_range(t_stack **a, t_stack **b, int *array, int count);
void	free_one_stack(t_stack **stack_a);
void	free_stack_array(t_stack **stack_a, int *array);
void	free_every_thing(t_stack **stack_a, t_stack **stack_b, int *array);
void	free_stack(t_stack **stack_a);
void	read_from_shell(char *string, t_stack **stack_a, t_stack **stack_b);
int		my_sort(int *tab, t_stack **stack_a, int l);
int		get_len(t_stack **stack_a);
int		do_pb_and_rb(t_stack **stack_a, t_stack **stack_b, int k);
int		check_is_sorted(int *array, t_stack **stack_a);
int		sort_small_stack(t_stack **stack_a, t_stack **b, int *array, int n);
int		ft_lstsize(t_stack **stack_b);
int		found_position(t_stack **stack_a, int *array, int demi_size, int n);
int		check_double(t_stack **stack_a);

#endif
