/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:05:35 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/29 23:55:35 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char *str)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	i = ft_atol(str, &error);
	if (i == 0 && error == 1)
		return (1);
	return (0);
}

t_stack	*start_stack(int index)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size_a = index;
	stack->size_b = 0;
	stack->stack_a = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->stack_a)
		return (free(stack), NULL);
	stack->stack_b = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->stack_b)
		return (free(stack->stack_a), free(stack), NULL);
	return (stack);
}

static void	push_swap(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	if (stack->size_a == 3)
		sort_three(stack);
	if (stack->size_a > 3 && stack->size_a <= 5)
		sort_five(stack);
	else
		radix_sort(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = create_stack(argc, argv);
	if (!stack)
		my_exit(stack, NULL);
	if (is_sorted(stack))
	{
		free_stack(stack);
		return (0);
	}
	push_swap(stack);
	free_stack(stack);
	return (0);
}
