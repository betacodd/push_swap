/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:57:06 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:21:21 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(int *arr, int value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	last_index(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i - 1);
}

void	push_to_b(t_push **data, int *arr, int index, int pos)
{
	int	len;

	len = (*data)->len_a;
	while ((*data)->len_a != len - 1)
	{
		if ((*data)->a->value == arr[index])
		{
			pb(data);
			if ((*data)->len_b > 2 && (*data)->len_b % 2 == 0)
				rb(data);
			if ((*data)->len_a == 0)
				return ;
		}
		else if (pos < ((*data)->len_a) / 2)
			ra(data);
		else if (pos >= ((*data)->len_a) / 2)
			rra(data);
	}
}

void	push_to_a(t_push **data, int *arr, int index, int pos)
{
	int	len;

	len = (*data)->len_b;
	while ((*data)->len_b != len - 1)
	{
		if ((*data)->b->value == arr[index])
			pa(data);
		else if (pos < ((*data)->len_b) / 2)
			rb(data);
		else if (pos >= ((*data)->len_b) / 2)
			rrb(data);
	}
}

void	update_tmp_and_pos(t_push **data, t_stack **tmp, int *pos)
{
	if ((*tmp)->next != NULL)
	{
		*tmp = (*tmp)->next;
		(*pos)++;
	}
	else
	{
		*tmp = (*data)->a;
		*pos = 1;
	}
}
