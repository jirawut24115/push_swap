/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:44:18 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/11 13:01:36 by jchompoo         ###   ########.fr       */
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
	swap(f->stack_a);
	swap(f->stack_b);
}

void	swap_a(frame *f)
{
	swap(f->stack_a);
}

void	swap_b(frame *f)
{
	swap(f->stack_b);
}
