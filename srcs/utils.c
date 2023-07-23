/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:23:24 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:29:13 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	safe_atoi(char *str, int *out)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*(str++) - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
			return (-1);
	}
	if (*str != '\0')
		return (-1);
	*out = (int)(sign * res);
	return (0);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*iter;

	tmp = stack;
	while (tmp)
	{
		iter = tmp->next;
		while (iter)
		{
			if (tmp->value == iter->value)
				return (1);
			iter = iter->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_push **data)
{
	int			val;
	t_stack		*tmp;

	tmp = (*data)->a;
	val = INT_MIN;
	while (tmp != NULL)
	{
		if (tmp->value < val)
			return (0);
		val = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}
