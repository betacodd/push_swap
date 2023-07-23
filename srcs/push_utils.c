/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:33:46 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:26:37 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push	*new_t_push(int len, char **argv)
{
	t_push	*new;

	new = (t_push *)malloc(sizeof(t_push));
	if (new == NULL)
		exit(0);
	remove_first_element(argv);
	new->len_a = len;
	new->len_b = 0;
	new->a = new_stack(len, argv);
	if (!(new->a) || check_duplicates(new->a))
	{
		free_stack(new->a);
		free(new);
		return (NULL);
	}
	new->b = NULL;
	return (new);
}

int	len_stack(t_stack *stack)
{
	int	len;

	len = 0;
	if (stack == NULL)
		return (len);
	else
		return (len_stack(stack->next) + 1);
}
