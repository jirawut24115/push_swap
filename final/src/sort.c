/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:14:01 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 23:01:12 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->stack_a[0] == stack->size_a + stack->size_b - 1)
		ra(stack);
	else if (stack->stack_a[1] == stack->size_a + stack->size_b - 1)
		rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}

void	sort_five(t_stack *stack)
{
	while (stack->size_b < 2)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
			pb(stack);
		else
			ra(stack);
	}
	if (stack->stack_b[0] == 0)
		sb(stack);
	sort_three(stack);
	pa(stack);
	pa(stack);
}

static int	find_bit_size(int size)
{
	int	result;

	result = 0;
	while (size > 0)
	{
		size /= 2;
		result++;
	}
	return (result);
}

void	radix_sort(t_stack *stack)
{
	int	bit_size;
	int	size;
	int	i;

	bit_size = find_bit_size(stack->size_a);
	i = 0;
	while (i < bit_size)
	{
		size = stack->size_a;
		while (size && !is_sorted(stack))
		{
			if (((stack->stack_a[0] >> i) & 1) == 0)
				pb(stack);
			else
				ra(stack);
			size--;
		}
		while (stack->size_b != 0)
			pa(stack);
		i++;
	}
	while (stack->size_b != 0)
		pa(stack);
}
