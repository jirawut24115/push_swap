#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int *collection;
	int	capacity;
	int	size;
} Stacks;

typedef struct
{
	Stacks *stack_a;
	Stacks *stack_b;
} frame;

Stacks *create_stack(int capacity);
void	destroy_stack(frame *f);
bool	is_full(Stacks *stack);
bool	is_empty(Stacks *stack);
bool	pop(Stacks *stack, int *item);
bool	push(Stacks *stack, int item);
bool	peek(Stacks *stack, int *item);
void	swap(Stacks	*stack_a);
void	swap_s(frame *f);

#endif
