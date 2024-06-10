/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <salaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:16:57 by salaoui           #+#    #+#             */
/*   Updated: 2024/06/09 19:17:49 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	my_sort(int *tab, t_stack **stack_a, int l)
{
	int		min;
	t_stack	*temp;

	temp = *stack_a;
	min = temp->data;
	while (temp && is_num_in(temp->data, tab, l) == 0)
	{
		temp = temp->next_data;
		min = temp->data;
	}
	if (temp == NULL)
		return (min);
	while (temp)
	{
		if (min > temp->data && is_num_in(temp->data, tab, l) == 1)
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
	char	*string;
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
	string = get_next_line(0);
	while (string != NULL)
	{
		read_from_shell(string, stack_a, &stack_b, array);
		free(string);
		string = get_next_line(0);
	}
	free_stack(&stack_b);
	return (check_is_correct(array, stack_a, count));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		count;

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
	count = check_double(&stack_a);
	return (main_2(&stack_a, count));
}
