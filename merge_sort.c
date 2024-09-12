/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:00:24 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 12:20:25 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	small_sort(t_deque *pdeque)
{
	if (pdeque->a->element_count == 6)
		six_element_sort(pdeque);
	else if (pdeque->a->element_count == 5)
		five_element_sort(pdeque);
	else if (pdeque->a->element_count == 4)
		four_element_sort(pdeque);
	else if (pdeque->a->element_count == 3)
		three_element_sort(pdeque);
	else if (pdeque->a->element_count == 2)
		two_element_sort(pdeque);
}

void	divide(t_deque *pdeque)
{
	int	depth;
	int	max_triangle;
	int	triangle_idx;
	int	order;
	int	triangle_size;

	depth = get_depth(pdeque);
	max_triangle = power(3, depth);
	get_triangle_size(pdeque, depth, 'a');
	triangle_idx = -1;
	while (++triangle_idx < max_triangle)
	{
		order = get_order(triangle_idx);
		triangle_size = pdeque->num_array[triangle_idx];
		triangle_to_b(pdeque, order, triangle_size);
	}
}

void	merge_sort(t_deque *pdeque)
{
	if (pdeque->a->element_count <= 6)
	{
		small_sort(pdeque);
	}
	else
	{
		divide(pdeque);
	}
}
