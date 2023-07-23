/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:25:18 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:26:47 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two_val(t_push **data)
{
	if ((*data)->a->value > (*data)->a->next->value)
		sa(data);
}

void	sort_three_val(t_push **data)
{
	int	a;
	int	b;
	int	c;

	a = (*data)->a->value;
	b = (*data)->a->next->value;
	c = (*data)->a->next->next->value;
	if (a > b && b < c && c > a)
		sa(data);
	if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	if (a > b && a > c && b < c)
		ra(data);
	if (a < b && b > c && c > a)
	{
		sa(data);
		ra(data);
	}
	if (a < b && a > c && b > c)
		rra(data);
}

void	sort_four_val(t_push **data)
{
	int	min;
	int	index;

	min = find_min(&((*data)->a));
	index = find_min_index(&((*data)->a), min);
	while ((*data)->len_a != 3)
	{
		if ((*data)->a->value == min)
			pb(data);
		else if (index < ((*data)->len_a) / 2)
			ra(data);
		else if (index >= ((*data)->len_a) / 2)
			rra(data);
	}
	sort_three_val(data);
	pa(data);
}

void	sort_five_val(t_push **data)
{
	int	min;
	int	index;

	min = find_min(&((*data)->a));
	index = find_min_index(&((*data)->a), min);
	while ((*data)->len_a != 3)
	{
		if ((*data)->a->value == min)
		{
			pb(data);
			min = find_min(&((*data)->a));
			index = find_min_index(&((*data)->a), min);
		}
		else if (index < ((*data)->len_a) / 2)
			ra(data);
		else if (index >= ((*data)->len_a) / 2)
			rra(data);
	}
	sort_three_val(data);
	pa(data);
	pa(data);
}
