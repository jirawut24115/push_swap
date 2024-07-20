/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:21:37 by jichompo          #+#    #+#             */
/*   Updated: 2024/06/23 23:07:37 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static	int	ft_isspace(int c)
// {
// 	if (c == '\n' || c == '\t' || c == '\f' || c == '\r'
// 		|| c == '\v' || c == ' ' || c == '0')
// 		return (1);
// 	return (0);
// }V

static int	find_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static char	*refine_string(char *str, int *error)
{
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
		*error = 1;
	return (str);
}

int	ft_atol(char *str, int *error)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = find_sign(*str);
		str++;
	}
	str = refine_string(str, error);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return (result);
}
