/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:01:59 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:27:09 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_elem(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*add_back(t_stack *stack, int value)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem(value);
	tmp->next->prev = tmp;
	return (stack);
}

t_stack	*new_stack(int len, char **input)
{
	t_stack	*head;
	int		i;
	int		value;

	if (safe_atoi(input[0], &value) != 0)
		return (NULL);
	head = new_elem(value);
	i = 1;
	while (i < len)
	{
		if (safe_atoi(input[i], &value) != 0)
		{
			free_stack(head);
			return (NULL);
		}
		head = add_back(head, value);
		i++;
	}
	return (head);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putstr_fd(" ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		stack = stack->next;
		free(tmp);
		tmp = stack;
	}
}
