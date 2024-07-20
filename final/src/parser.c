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
	if (ft_strlen(str) == 1 && !(ft_isdigit(*str)))
		return (-1);
	if ((*str == '-' || *str == '+'))
	{
		if (!ft_isdigit(*(++str)))
			return (-1);
	}
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

static t_stack	*init_stack(char *argv)
{
	int		index;
	int		error;
	t_stack	*stack;
	char	**temp;

	index = 0;
	error = 0;
	temp = ft_split(argv, 32);
	while (temp[index])
		index++;
	stack = start_stack(index);
	if (!stack)
		return (NULL);
	assign_stack(stack, temp, &error);
	if (check_duplicate(stack) || error == 1)
	{
		free(argv);
		ft_free_split(temp);
		my_exit(stack, NULL);
	}
	refine_stack(stack);
	ft_free_split(temp);
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
	stack = NULL;
	while (index < argc)
	{
		if (is_empty(argv[index]))
			my_exit(stack, str);
		str = ft_free_strjoin(str, argv[index]);
		if (index != argc - 1)
			str = ft_free_strjoin(str, " ");
		index++;
	}
	if (check_string(str) == -1)
		my_exit(stack, str);
	stack = init_stack(str);
	free(str);
	return (stack);
}
