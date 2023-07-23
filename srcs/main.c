/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:11:12 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:25:05 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	remove_first_element(char **argv)
{
	if (argv == NULL || *argv == NULL)
		return ;
	while (*(argv + 1))
	{
		*argv = *(argv + 1);
		argv++;
	}
	*argv = NULL;
}

int	main(int argc, char **argv)
{
	t_push	*data;

	if (argc < 2)
		exit(0);
	data = new_t_push(argc - 1, argv);
	if (!data)
		exit(ft_printf("Error\n"));
	if (!is_sorted(&data))
		push_swap(&data);
	free_stack(data->a);
	free_stack(data->b);
	free(data);
	return (0);
}
