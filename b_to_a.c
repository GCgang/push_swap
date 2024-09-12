/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:02:23 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/18 16:37:44 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	b_to_a_push(t_deque *pdeque, int max_triangle)
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
		pa(pdeque, 1);
}

void	b_to_a(t_deque *pdeque, int max_triangle)
{
	int	i;
	int	order;

	i = -1;
	while (++i < max_triangle)
	{
		order = get_order(i);
		if (order % 2 == ASCENDING)
		{
			b_to_a_mege(pdeque, max_triangle, ASCENDING, i);
		}
		else if (order % 2 == DESCENDING)
		{
			b_to_a_mege(pdeque, max_triangle, DESCENDING, i);
		}
	}
}

void	b_to_a_mege(t_deque *pdeque, int max_triangle, int order, int i)
{
	int	max_iter;
	int	limit[3];
	int	n[3];
	int	min_max;

	limit[0] = pdeque->num_array[i];
	limit[1] = pdeque->num_array[max_triangle * 2 - 1 - i];
	limit[2] = pdeque->num_array[max_triangle * 3 - 1 - i];
	max_iter = limit[0] + limit[1] + limit[2];
	while (max_iter--)
	{
		if (limit[0] == 0 && limit[1] == 0 && limit[2] == 0)
			break ;
		setting_n(pdeque, n, limit, 'a');
		min_max = get_min_max(n, limit, order);
		rra_pa_rrb_pa(pdeque, min_max, n, limit);
	}
}

void	rra_pa_rrb_pa(t_deque *pdeque, int min_max, int *n, int *limit)
{
	if (min_max == n[0] && limit[0] != 0)
	{
		limit[0]--;
		rra(pdeque, 1);
	}
	if (min_max == n[1] && limit[1] != 0)
	{
		if (min_max == n[2])
			limit[2]--;
		limit[1]--;
		pa(pdeque, 1);
	}
	if (min_max == n[2] && limit[2] != 0)
	{
		if (min_max == n[1])
			limit[1]--;
		limit[2]--;
		rrb(pdeque, 1);
		pa(pdeque, 1);
	}
}
