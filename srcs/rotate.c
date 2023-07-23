/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:28:05 by elevy             #+#    #+#             */
/*   Updated: 2023/06/30 10:01:30 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_push **data)
{
	t_stack	*tmp;

	if ((*data)->a == NULL || (*data)->a->next == NULL)
		return ;
	tmp = (*data)->a;
	while ((*data)->a->next != NULL)
		(*data)->a = (*data)->a->next;
	(*data)->a->next = tmp;
	tmp->prev = (*data)->a->next;
	(*data)->a = tmp->next;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_push **data)
{
	t_stack	*tmp;

	if ((*data)->b == NULL || (*data)->b->next == NULL)
		return ;
	tmp = (*data)->b;
	while ((*data)->b->next != NULL)
		(*data)->b = (*data)->b->next;
	(*data)->b->next = tmp;
	tmp->prev = (*data)->b->next;
	(*data)->b = tmp->next;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_push **data)
{
	ra(data);
	rb(data);
	ft_printf("rr\n");
}
