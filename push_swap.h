#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct
{
	int *collection;
	int	capacity;
	int	size;
} Stacks;

Stacks *create_stack(int capacity);
void	destroy_stack(Stacks *stack);
bool	is_full(Stacks *stack);
bool	is_empty(Stacks *stack);
bool	pop(Stacks *stack, int *item);
bool	push(Stacks *stack, int item);
bool	peek(Stacks *stack, int *item);

#endif
