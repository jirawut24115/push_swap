/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:53:23 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/11 13:53:26 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stacks	*create_stack(int capacity)
{
	if (capacity <= 0)
		return (NULL);
	Stacks *stack = malloc(sizeof(Stacks));
	if (!stack) return NULL;

	stack->collection = malloc(sizeof(int) * capacity);
	if(!stack->collection)
	{
		free(stack);
		return NULL;
	}
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

void	destroy_stack(frame *f)
{
	free(f->stack_a->collection);
	free(f->stack_a);
	free(f->stack_b->collection);
	free(f->stack_b);
}