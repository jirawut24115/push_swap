/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:16:35 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/29 23:55:43 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ' && *str != '-' && *str != '+')
			return (-1);
		if ((*str == '-' || *str == '+')
			&& (!ft_isdigit(*(str + 1)) || *(str - 1) != 32))
			return (-1);
		str++;
	}
	return (0);
}

static void	reassign(t_stack *stack, int *temp)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		stack->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}

static void	refine_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * stack->size_a);
	if (!temp)
		return ;
	while (i < stack->size_a)
	{
		j = 0;
		k = 0;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				k++;
			j++;
		}
		temp[i] = k;
		i++;
	}
	i = 0;
	reassign(stack, temp);
}

static t_stack	*init_stack(char **argv)
{
	int		index;
	int		error;
	t_stack	*stack;

	index = 0;
	error = 0;
	while (argv[index])
		index++;
	stack = start_stack(index);
	index = 0;
	while (index < stack->size_a && argv[index])
	{
		if (check_overflow(argv[index]))
			return (free_stack(stack), NULL);
		stack->stack_a[index] = ft_atol(argv[index], &error);
		index++;
	}
	if (check_duplicate(stack) || error == 1)
		return (free_stack(stack), NULL);
	refine_stack(stack);
	return (stack);
}

t_stack	*create_stack(int argc, char **argv)
{
	char	*str;
	int		index;
	t_stack	*stack;

	index = 1;
	str = malloc(sizeof(char) + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (index < argc)
	{
		if (is_empty(argv[index]))
			return (free(str), NULL);
		str = ft_free_strjoin(str, argv[index]);
		str = ft_free_strjoin(str, " ");
		index++;
	}
	if (check_string(str) == -1)
		return (free(str), NULL);
	argv = ft_split(str, 32);
	stack = init_stack(argv);
	return (ft_free_split(argv), free(str), stack);
}
