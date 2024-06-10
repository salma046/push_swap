/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:20:21 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 12:33:04 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next_data;
}	t_stack;

void	ft_atoi(t_stack **stack_a, const char *str);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	read_from_shell(char *string, t_stack **a, t_stack **b, int *array);
void	free_one_stack(t_stack **stack_a);
void	free_stack_array(t_stack **stack_a, int *array);
void	free_every_thing(t_stack **stack_a, t_stack **stack_b, int *array);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	sb(t_stack **stack_b);
void	free_stack(t_stack **stack_a);
int		check_double(t_stack **stack_a);
int		ft_lstsize(t_stack **stack_b);
int		check_is_correct(int *array, t_stack **stack_a, int count);
int		ft_strcmp(char *s1, char *s2);

#endif
