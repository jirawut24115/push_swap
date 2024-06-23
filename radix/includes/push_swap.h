/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:06:58 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 22:06:28 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

//utils
int		ft_atol(char *str, int *error);
int		is_empty(char *s);
int		check_duplicate(t_stack *stack);
int		is_sorted(t_stack *stack);
char	*ft_free_strjoin(char *s1, char *s2);
void	free_stack(t_stack *stack);

//parser
t_stack	*create_stack(int argc, char **argv);
t_stack	*start_stack(int index);

//operations
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

//sort
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	radix_sort(t_stack *stack);

#endif
