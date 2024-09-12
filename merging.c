/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:59:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/18 16:36:49 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	merging(t_deque *pdeque)
{
	int	depth;
	int	max_triangle;

	depth = get_depth(pdeque);
	while (depth)
	{
		max_triangle = power(3, depth - 1);
		if (isdeque_empty(pdeque->b) == TRUE)
		{
			get_triangle_size(pdeque, depth, 'a');
			a_to_b_push(pdeque, max_triangle);
			a_to_b(pdeque, max_triangle);
		}
		else if (isdeque_empty(pdeque->a) == TRUE)
		{
			get_triangle_size(pdeque, depth, 'b');
			b_to_a_push(pdeque, max_triangle);
			b_to_a(pdeque, max_triangle);
		}
		depth--;
	}
	is_sorted_b(pdeque);
}

void	is_sorted_b(t_deque *pdeque)
{
	if (isdeque_empty(pdeque->a) == TRUE && is_sorted(pdeque->b) == TRUE)
	{
		while (isdeque_empty(pdeque->b) != TRUE)
		{
			rrb(pdeque, 1);
			pa(pdeque, 1);
		}
	}
}

int	get_min_max(int *n, int *limit, int order)
{
	int	min_max;

	min_max = 0;
	if (order == ASCENDING)
	{
		if (limit[0] == 0)
			n[0] = -2147483648;
		if (limit[1] == 0)
			n[1] = -2147483648;
		if (limit[2] == 0)
			n[2] = -2147483648;
		min_max = get_n_max(n, 3);
	}
	else if (order == DESCENDING)
	{
		if (limit[0] == 0)
			n[0] = 2147483647;
		if (limit[1] == 0)
			n[1] = 2147483647;
		if (limit[2] == 0)
			n[2] = 2147483647;
		min_max = get_n_min(n, 3);
	}
	return (min_max);
}

void	setting_n(t_deque *pdeque, int *n, int *limit, char a_or_b)
{
	if (a_or_b == 'a')
	{
		if (limit[0] != 0)
			n[0] = pdeque->a->rear->value;
		if (limit[1] != 0)
			n[1] = pdeque->b->front->value;
		if (limit[2] != 0)
			n[2] = pdeque->b->rear->value;
	}
	else if (a_or_b == 'b')
	{
		if (limit[0] != 0)
			n[0] = pdeque->a->front->value;
		if (limit[1] != 0)
			n[1] = pdeque->a->rear->value;
		if (limit[2] != 0)
			n[2] = pdeque->b->rear->value;
	}
}
