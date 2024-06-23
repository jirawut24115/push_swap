/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:09:19 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 21:54:16 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	swap(&(stack->stack_a[0]), &(stack->stack_a[1]));
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	if (stack->size_b < 2)
		return ;
	swap(&(stack->stack_b[0]), &(stack->stack_b[1]));
	ft_printf("sb\n");
}

void	pb(t_stack *stack)
{
	int	temp;

	if (stack->size_a == 0)
		return ;
	temp = stack->stack_a[0];
	ft_memmove(stack->stack_b + 1, stack->stack_b, sizeof(int) * stack->size_b);
	stack->stack_b[0] = temp;
	stack->size_a--;
	stack->size_b++;
	ft_memmove(stack->stack_a, stack->stack_a + 1, sizeof(int) * stack->size_a);
	ft_printf("pb\n");
}

void	pa(t_stack *stack)
{
	int	temp;

	if (stack->size_b == 0)
		return ;
	temp = stack->stack_b[0];
	ft_memmove(stack->stack_a + 1, stack->stack_a, sizeof(int) * stack->size_a);
	stack->stack_a[0] = temp;
	stack->size_a++;
	stack->size_b--;
	ft_memmove(stack->stack_b, stack->stack_b + 1, sizeof(int) * stack->size_b);
	ft_printf("pa\n");
}
