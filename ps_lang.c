/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:44:18 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/13 21:04:25 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(Stacks *stack_a)
{
	int	temp;
	int idx = stack_a->size - 1;

	temp = stack_a->collection[idx];
	stack_a->collection[idx] = stack_a->collection[idx - 1];
	stack_a->collection[idx - 1] = temp;
}

void	swap_s(frame *f)
{
	if(is_empty(f->stack_a) || is_empty(f->stack_b) || f->stack_a->size <= 1 || f->stack_b->size <= 1)
		return ;
	swap(f->stack_a);
	swap(f->stack_b);
}

void	swap_a(frame *f)
{
	if(is_empty(f->stack_a) || f->stack_a->size <= 1)
		return;
	swap(f->stack_a);
}

void	swap_b(frame *f)
{
	if (is_empty(f->stack_b) || f->stack_b->size <= 1)
	swap(f->stack_b);
}

void	push_a(frame *f)
{
	if(is_empty(f->stack_b))
		return ;
	int pop_val;

	pop_val = 0;
	pop(f->stack_b, &pop_val);
	push(f->stack_a, pop_val);
}

void	push_b(frame *f)
{
	if(is_empty(f->stack_a))
		return ;
	int pop_val;

	pop_val = 0;
	pop(f->stack_a, &pop_val);
	push(f->stack_b, pop_val);
}

void	rotate_a(frame *f)
{
	int temp;
	int idx;

	idx = f->stack_a->size - 1; // top of stack
	temp = f->stack_a->collection[idx]; //set temp to top of stack
	while (idx > 0)
	{
		f->stack_a->collection[idx] = f->stack_a->collection[idx - 1];
		idx--;
	}
	f->stack_a->collection[idx] = temp;
}

void	rotate_b(frame *f)
{
	int	temp;
	int	idx;

	idx = f->stack_b->size - 1;
	temp = f->stack_b->collection[idx];
	while (idx > 0)
	{
		f->stack_b->collection[idx] = f->stack_b->collection[idx - 1];
		idx--;
	}
	f->stack_b->collection[idx] = temp;
}

void	rotate_r(frame *f)
{
	rotate_a(f);
	rotate_b(f);
}

void	reverse_rotate_a(frame *f)
{
	int	temp;
	int	idx;

	idx = 0;
	temp = f->stack_a->collection[idx];
	while (idx < f->stack_a->size - 1)
	{
		f->stack_a->collection[idx] = f->stack_a->collection[idx + 1];
		idx++;
	}
	f->stack_a->collection[idx] = temp;
}

void	reverse_rotate_b(frame *f)
{
	int	temp;
	int	idx;

	idx = 0;
	temp = f->stack_b->collection[idx];
	while (idx < f->stack_b->size - 1)
	{
		f->stack_b->collection[idx] = f->stack_b->collection[idx + 1];
		idx++;
	}
	f->stack_b->collection[idx] = temp;
}

void	reverse_rotate_r(frame *f)
{
	reverse_rotate_a(f);
	reverse_rotate_b(f);
}