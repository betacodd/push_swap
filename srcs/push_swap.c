/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:18:04 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:26:11 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_into_b(t_push **data, int *arr)
{
	int		range;
	int		index;
	int		arr_len;
	int		pos;
	t_stack	*tmp;

	tmp = (*data)->a;
	pos = 1;
	arr_len = (*data)->len_a;
	range = start_range((*data)->len_a);
	while (range - start_range(arr_len) < arr_len)
	{
		index = get_index(arr, tmp->value, arr_len);
		if (should_push_to_b(index, range))
		{
			push_to_b(data, arr, index, pos);
			tmp = (*data)->a;
			pos = 1;
			if ((*data)->len_a == 0)
				return ;
			range++;
		}
		update_tmp_and_pos(data, &tmp, &pos);
	}
}

void	sorting_b(t_push **data, int *arr)
{
	t_stack		*tmp;
	int			big_index;
	int			pos;

	tmp = (*data)->b;
	pos = 1;
	big_index = (*data)->len_b - 1;
	while ((*data)->len_b > 0)
	{
		while (tmp != NULL && tmp->value != arr[big_index])
		{
			tmp = tmp->next;
			pos++;
		}
		push_to_a(data, arr, big_index, pos);
		big_index--;
		tmp = (*data)->b;
		pos = 1;
		if ((*data)->len_b == 0)
			return ;
	}
}

void	sort_algorithm(t_push **data)
{
	int	*sorted_arr;

	sorted_arr = sorted_index(&((*data)->a), (*data)->len_a);
	if (!sorted_arr)
		return ;
	push_into_b(data, sorted_arr);
	sorting_b(data, sorted_arr);
	free(sorted_arr);
}

void	push_swap(t_push **data)
{
	if ((*data)->len_a == 2)
		sort_two_val(data);
	else if ((*data)->len_a == 3)
		sort_three_val(data);
	else if ((*data)->len_a == 4)
		sort_four_val(data);
	else if ((*data)->len_a == 5)
		sort_five_val(data);
	else
		sort_algorithm(data);
}
