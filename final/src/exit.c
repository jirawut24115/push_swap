/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:17:00 by jichompo          #+#    #+#             */
/*   Updated: 2024/07/05 15:17:03 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_exit(t_stack *stack, char *str)
{
	if (!stack && !str)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (stack)
	{
		if (stack->stack_a)
			free(stack->stack_a);
		if (stack->stack_b)
			free(stack->stack_b);
		free(stack);
	}
	if (str)
		free(str);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	assign_stack(t_stack *stack, char **temp, int *error)
{
	int	index;

	index = 0;
	while (index < stack->size_a && temp[index])
	{
		if (check_overflow(temp[index]))
			*error = 1;
		stack->stack_a[index] = ft_atol(temp[index], error);
		index++;
	}
}
