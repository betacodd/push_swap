/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:40:25 by elevy             #+#    #+#             */
/*   Updated: 2023/06/30 10:05:08 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_push **data)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*data)->a == NULL || (*data)->a->next == NULL)
		return ;
	tmp = (*data)->a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->prev = NULL;
	last->next = (*data)->a;
	(*data)->a->prev = last;
	(*data)->a = last;
	ft_printf("rra\n");
}

void	rrb(t_push **data)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((*data)->b == NULL || (*data)->b->next == NULL)
		return ;
	tmp = (*data)->b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->prev = NULL;
	last->next = (*data)->b;
	(*data)->b->prev = last;
	(*data)->b = last;
	ft_printf("rrb\n");
}

void	rrr(t_push **data)
{
	rra(data);
	rrb(data);
	ft_printf("rrr\n");
}
