/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:05:35 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 22:52:50 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*start_stack(int index)
{
	t_stack	*stack;

	stack = malloc(sizeof(stack));
	stack->size_a = index;
	stack->size_b = 0;
	stack->stack_a = (int *)malloc(sizeof(int) * stack->size_a);
	stack->stack_b = (int *)malloc(sizeof(int) * stack->size_a);
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
		return (ft_printf("Error\n"), -1);
	if (is_sorted(stack))
		return (free_stack(stack), 0);
	push_swap(stack);
	free_stack(stack);
	return (0);
}
