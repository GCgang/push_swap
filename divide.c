/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:02:04 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 12:23:57 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

int	get_depth(t_deque *pdeque)
{
	int	total_count;
	int	depth;

	total_count = pdeque->tot_cnt;
	depth = 0;
	while (1)
	{
		if (total_count < 6)
			break ;
		total_count = total_count / 3 + total_count % 3;
		depth++;
	}
	return (depth);
}

int	power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power--)
		res *= nb;
	return (res);
}

int	get_order(int idx)
{
	int	flip;
	int	range;
	int	mirror;
	int	dist;

	flip = 0;
	while (idx > 0)
	{
		range = 0;
		while (idx / power(3, range))
			range++;
		mirror = power(3, range - 1);
		dist = idx - mirror;
		dist %= mirror;
		idx = mirror - dist - 1;
		flip++;
	}
	return (flip);
}

void	get_triangle_size(t_deque *pdeque, int depth, char deque)
{
	int	i;
	int	j;
	int	tmp;
	int	arr_size;

	i = -1;
	arr_size = 1;
	if (deque == 'a')
		pdeque->num_array[0] = pdeque->a->element_count;
	else if (deque == 'b')
		pdeque->num_array[0] = pdeque->b->element_count;
	while (++i < depth)
	{
		j = -1;
		while (++j < arr_size)
		{
			tmp = pdeque->num_array[j];
			pdeque->num_array[j] = tmp / 3;
			pdeque->num_array[arr_size + j] = ((tmp / 3) + (tmp % 3));
			pdeque->num_array[arr_size * 2 + j] = tmp / 3;
		}
		arr_size *= 3;
	}
}

void	triangle_to_b(t_deque *pdeque, int order, int triangle_size)
{
	if (order % 2 == ASCENDING)
	{
		ascending_order_to_b(pdeque, triangle_size);
	}
	else if (order % 2 == DESCENDING)
	{
		descending_order_to_b(pdeque, triangle_size);
	}
}
