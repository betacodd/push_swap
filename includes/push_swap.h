/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <elevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:14 by elevy             #+#    #+#             */
/*   Updated: 2023/07/23 19:35:52 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
	struct s_stack		*prev;
}			t_stack;

typedef struct s_push
{
	int				len_a;
	int				len_b;
	t_stack			*a;
	t_stack			*b;
}			t_push;

void	push_swap(t_push **data);
void	print_stack(t_stack *stack);
void	remove_first_element(char **argv);
void	free_stack(t_stack *stack);
void	sort_two_val(t_push **data);
void	sort_three_val(t_push **data);
void	sort_four_val(t_push **data);
void	sort_five_val(t_push **data);
void	swap(int *xp, int *yp);
void	bubble_sort(int *tab, int len);
void	push_into_b(t_push **data, int *arr);
void	sorting_b(t_push **data, int *arr);
void	push_to_b(t_push **data, int *arr, int index, int pos);
void	push_to_a(t_push **data, int *arr, int index, int pos);
void	update_tmp_and_pos(t_push **data, t_stack **tmp, int *pos);
void	sa(t_push **data);
void	sb(t_push **data);
void	ss(t_push **data);
void	pa(t_push **data);
void	pb(t_push **data);
void	ra(t_push **data);
void	rb(t_push **data);
void	rr(t_push **data);
void	rra(t_push **data);
void	rrb(t_push **data);
void	rrr(t_push **data);
t_stack	*new_elem(int val);
t_stack	*new_stack(int len, char **input);
t_stack	*add_back(t_stack *stack, int value);
t_push	*new_t_push(int len, char **arg);
int		safe_atoi(char *str, int *out);
int		check_duplicates(t_stack *stack);
int		len_stack(t_stack *stack);
int		find_min(t_stack **stack);
int		find_min_index(t_stack **stack, int nb);
int		is_sorted(t_push **data);
int		*sorted_index(t_stack **stack, int len);
int		get_index(int *arr, int value, int len);
int		start_range(int len);
int		last_index(int *arr);
int		should_push_to_b(int index, int range);
#endif