/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:59:04 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/18 15:46:45 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	set_n(t_deque *pdeque, int *n, int cnt)
{
	if (cnt == 3 || cnt == 4)
	{
		n[0] = pdeque->a->front->value;
		n[1] = pdeque->a->front->next->value;
		n[2] = pdeque->a->rear->value;
	}
	if (cnt == 4)
	{
		n[2] = pdeque->a->rear->prev->value;
		n[3] = pdeque->a->rear->value;
	}
	else if (cnt == 5 || cnt == 6)
	{
		n[0] = pdeque->a->front->value;
		n[1] = pdeque->a->front->next->value;
		n[2] = pdeque->a->front->next->next->value;
		n[3] = pdeque->a->rear->prev->value;
		n[4] = pdeque->a->rear->value;
	}
	if (cnt == 6)
	{
		n[3] = pdeque->a->rear->prev->prev->value;
		n[4] = pdeque->a->rear->prev->value;
		n[5] = pdeque->a->rear->value;
	}
}

int	get_n_max(int *n, int cnt)
{
	int	i;
	int	max;

	max = n[0];
	i = -1;
	while (++i < cnt - 1)
	{
		if (max < n[i + 1])
			max = n[i + 1];
	}
	return (max);
}

int	get_n_min(int *n, int cnt)
{
	int	i;
	int	min;

	min = n[0];
	i = -1;
	while (++i < cnt - 1)
	{
		if (min > n[i + 1])
			min = n[i + 1];
	}
	return (min);
}

void	ascending_order_to_b(t_deque *pdeque, int triangle_size)
{
	if (triangle_size == 6)
		ascending_six_to_b(pdeque);
	else if (triangle_size == 5)
		ascending_five_to_b(pdeque);
	else if (triangle_size == 4)
		ascending_four_to_b(pdeque);
	else if (triangle_size == 3)
		ascending_three_to_b(pdeque);
	else if (triangle_size == 2)
		ascending_two_to_b(pdeque);
	else if (triangle_size == 1)
		pb(pdeque, 1);
}

void	descending_order_to_b(t_deque *pdeque, int triangle_size)
{
	if (triangle_size == 6)
		decending_six_to_b(pdeque);
	else if (triangle_size == 5)
		decending_five_to_b(pdeque);
	else if (triangle_size == 4)
		decending_four_to_b(pdeque);
	else if (triangle_size == 3)
		decending_three_to_b(pdeque);
	else if (triangle_size == 2)
		decending_two_to_b(pdeque);
	else if (triangle_size == 1)
		pb(pdeque, 1);
}
