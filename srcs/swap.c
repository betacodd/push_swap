/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:43:59 by elevy             #+#    #+#             */
/*   Updated: 2023/06/29 19:31:53 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_push **data)
{
	int	tmp;

	if ((*data)->a->next == 0)
		return ;
	tmp = (*data)->a->value;
	(*data)->a->value = (*data)->a->next->value;
	(*data)->a->next->value = tmp;
	ft_printf("sa\n");
}

void	sb(t_push **data)
{
	int	tmp;

	if ((*data)->b->next == 0)
		return ;
	tmp = (*data)->b->value;
	(*data)->b->value = (*data)->b->next->value;
	(*data)->b->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_push **data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
}
