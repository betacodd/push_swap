/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:36:12 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:24:43 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	start_range(int len)
{
	int	i;
	int	y;

	i = 1;
	y = 15;
	while (i <= len)
	{
		if (len > 100 && i % 100 == 0)
			y = y + 2;
		i++;
	}
	return (y);
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubble_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < len - 1)
	{
		swapped = 0;
		j = 0;
		while (j < len - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	*sorted_index(t_stack **stack, int len)
{
	t_stack		*tmp;
	int			*tab;
	int			i;

	tab = (int *)malloc(len * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	tmp = (*stack);
	while (tmp != NULL)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(tab, len);
	return (tab);
}

int	should_push_to_b(int index, int range)
{
	return (index < range);
}
