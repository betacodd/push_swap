/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:09:53 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:26:56 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack **stack)
{
	int			min;
	t_stack		*tmp;

	min = INT_MAX;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_min_index(t_stack **stack, int nb)
{
	int			index;
	t_stack		*tmp;

	tmp = *stack;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->value == nb)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}
