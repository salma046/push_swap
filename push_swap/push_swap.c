/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:38:12 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 18:44:39 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_in(int a, int *arr, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (a == arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	my_sort(int *array, t_stack **stack_a, int l)
{
	int		min;
	t_stack	*temp;

	temp = *stack_a;
	min = temp->data;
	while (temp && is_num_in(temp->data, array, l) == 0)
	{
		temp = temp->next_data;
		min = temp->data;
	}
	if (temp == NULL)
		return (min);
	while (temp)
	{
		if (min > temp->data && is_num_in(temp->data, array, l) == 1)
			min = temp->data;
		temp = temp->next_data;
	}
	return (min);
}

void	ft_space_err(const char *str, t_stack **stack_a)
{
	int	space;
	int	i;

	i = 0;
	space = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			space++;
		i++;
	}
	if (i == space)
	{
		free_stack(stack_a);
		exit(write(2, "Error\n", 6));
	}
}

int	main_2(t_stack **stack_a, int count)
{
	int		*array;
	int		l;
	t_stack	*stack_b;

	stack_b = NULL;
	array = (int *)malloc((count + 1) * sizeof(int));
	if (array == NULL)
		free_one_stack(stack_a);
	l = 0;
	while (l < count)
	{
		array[l] = my_sort(array, stack_a, l);
		l++;
	}
	array[l] = '\0';
	if (check_is_sorted(array, stack_a) == 1)
		return (0);
	if (count == 2 || count == 3 || count == 4 || count == 5)
		return (sort_small_stack(stack_a, &stack_b, array, count));
	take_apropriate_range(stack_a, &stack_b, array, count);
	sorting_it_again(stack_a, &stack_b, array, count);
	free_every_thing(stack_a, &stack_b, array);
	return (0);
}

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	if (ac < 2)
		return (0);
	while (av[i])
	{
		ft_space_err(av[i], &stack_a);
		ft_atoi(&stack_a, av[i]);
		i++;
	}
	stack_a->count = check_double(&stack_a);
	return (main_2(&stack_a, stack_a->count));
}
