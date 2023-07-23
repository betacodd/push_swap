/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:49:05 by elevy             #+#    #+#             */
/*   Updated: 2023/07/02 17:33:49 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_push **data)
{
	t_stack	*tmp;

	if ((*data)->b == NULL)
		return ;
	tmp = (*data)->b->next;
	(*data)->b->next = (*data)->a;
	if ((*data)->a != NULL)
		(*data)->a->prev = (*data)->b;
	else
		(*data)->b->next = NULL;
	(*data)->a = (*data)->b;
	(*data)->b = tmp;
	((*data)->len_a) = ((*data)->len_a) + 1;
	((*data)->len_b) = ((*data)->len_b) - 1;
	ft_printf("pa\n");
}

void	pb(t_push **data)
{
	t_stack	*tmp;

	if ((*data)->a == NULL)
		return ;
	tmp = (*data)->a->next;
	(*data)->a->next = (*data)->b;
	if ((*data)->b != NULL)
		(*data)->b->prev = (*data)->a;
	else
		(*data)->a->next = NULL;
	(*data)->b = (*data)->a;
	(*data)->a = tmp;
	((*data)->len_a) = ((*data)->len_a) - 1;
	((*data)->len_b) = ((*data)->len_b) + 1;
	ft_printf("pb\n");
}
