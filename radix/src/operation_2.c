/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:11:14 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 21:55:27 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	ft_memmove(stack->stack_a, stack->stack_a + 1,
		sizeof(int) * (stack->size_a - 1));
	stack->stack_a[stack->size_a - 1] = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->stack_b[0];
	ft_memmove(stack->stack_b, stack->stack_b + 1,
		sizeof(int) * (stack->size_b - 1));
	stack->stack_b[stack->size_b - 1] = temp;
	ft_printf("rb\n");
}

void	rra(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[stack->size_a - 1];
	ft_memmove(stack->stack_a + 1, stack->stack_a,
		sizeof(int) * (stack->size_a - 1));
	stack->stack_a[0] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->stack_b[stack->size_b - 1];
	ft_memmove(stack->stack_b + 1, stack->stack_b,
		sizeof(int) * (stack->size_b - 1));
	stack->stack_b[0] = temp;
	ft_printf("rrb\n");
}
