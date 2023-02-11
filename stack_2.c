/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:42:09 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/11 10:54:13 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_full(Stacks *stack)
{
	return stack->capacity == stack->size;
}

bool	is_empty(Stacks *stack)
{
	return stack->size == 0;
}

bool	push(Stacks *stack, int item)
{
	if (is_full(stack)) return false;
	stack->collection[stack->size] = item;
	stack->size++;
	return true;
}

 bool	pop(Stacks *stack, int *item)
 {
	 if (is_empty(stack)) return false;
	 stack->size--;
	*item = stack->collection[stack->size];
	 return true;
 }

bool	peek(Stacks *stack, int *item)
{
	if (is_empty(stack)) return false;
	*item = stack->collection[stack->size - 1];
	return true;
}