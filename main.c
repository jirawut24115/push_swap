#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

int	main(void)
{
	Stacks *stack_a;

	stack_a = create_stack(5);
	if(stack_a)
	{
		printf("Stack created\n");
		printf("Stack size is %d\n", stack_a->size);
		printf("Stack capacity is %d\n", stack_a->capacity);
	}

	destroy_stack(stack_a);
	if(!stack_a) printf("Stack destroyed\n");
	return 0;
}

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

void	destroy_stack(Stacks *stack)
{
	free(stack->collection);
	free(stack);
}

bool	is_full(Stacks *stack)
{
	return stack->capacity == stack->size;
}

bool	is_empty(Stacks *stack)
{
	return stack->size == 0;
}

bool	pop(Stacks *stack, int *item)
{
	
}
