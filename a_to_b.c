/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:02:16 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 19:57:13 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	a_to_b_push(t_deque *pdeque, int max_triangle)
{
	int	i;
	int	j;
	int	iter_max;

	i = -1;
	iter_max = 0;
	while (++i < max_triangle)
		iter_max += pdeque->num_array[i];
	j = -1;
	while (++j < iter_max)
		pb(pdeque, 1);
}

void	a_to_b(t_deque *pdeque, int max_triangle)
{
	int	i;
	int	order;

	i = -1;
	while (++i < max_triangle)
	{
		order = get_order(i);
		if (order % 2 == ASCENDING)
		{
			a_to_b_merge(pdeque, max_triangle, ASCENDING, i);
		}
		else if (order % 2 == DESCENDING)
		{
			a_to_b_merge(pdeque, max_triangle, DESCENDING, i);
		}
	}
}

void	a_to_b_merge(t_deque *pdeque, int max_triangle, int order, int i)
{
	int	max_iter;
	int	limit[3];
	int	n[3];
	int	min_max;

	limit[0] = pdeque->num_array[max_triangle * 2 - 1 - i];
	limit[1] = pdeque->num_array[i];
	limit[2] = pdeque->num_array[max_triangle * 3 - 1 - i];
	max_iter = limit[0] + limit[1] + limit[2];
	while (max_iter--)
	{
		if (limit[0] == 0 && limit[1] == 0 && limit[2] == 0)
			break ;
		setting_n(pdeque, n, limit, 'b');
		min_max = get_min_max(n, limit, order);
		pb_rra_pb_rrb(pdeque, min_max, n, limit);
	}
}

void	pb_rra_pb_rrb(t_deque *pdeque, int min_max, int *n, int *limit)
{
	if (min_max == n[0] && limit[0] != 0)
	{
		if (min_max == n[1])
			limit[1]--;
		limit[0]--;
		pb(pdeque, 1);
	}
	if (min_max == n[1] && limit[1] != 0)
	{
		if (min_max == n[0])
			limit[0]--;
		limit[1]--;
		rra(pdeque, 1);
		pb(pdeque, 1);
	}
	if (min_max == n[2] && limit[2] != 0)
	{
		limit[2]--;
		rrb(pdeque, 1);
	}
}
