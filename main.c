/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:41:55 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/11 14:54:51 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(Stacks *stack_a, Stacks *stack_b);

int	main(void)
{
	frame *f;
	f->stack_a = create_stack(10);
	f->stack_b = create_stack(10);
	if(f->stack_a == NULL || f->stack_b == NULL)
	{
		printf("Error creating stacks\n");
		return (1);
	}
	if (is_empty(f->stack_a) && (is_empty(f->stack_b))) printf("Both stack is empty\n");
	for (int i = 0; i < 5; i++)
		{
			push(f->stack_a, i);
			push(f->stack_b, i);
			printf("push %d to both stack\n", i);
		}

	// int *pop_val;
	// pop(f->stack_b, pop_val);
	print_stacks(f->stack_a, f->stack_b);
	swap_s(f);
	print_stacks(f->stack_a, f->stack_b);
	destroy_stack(f);
	return 0;
}

void	print_stacks(Stacks *stack_a, Stacks *stack_b)
{
	int i = stack_a->size - 1;
	//int j = stack_b->size - 1;

	while (i >= 0)
	{
		printf("%d %d\n", stack_a->collection[i], stack_b->collection[i]);
		i--; 
	}
	printf("_ _\na b\n");
}
