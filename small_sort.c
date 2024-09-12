/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:36:57 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 17:00:26 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	two_element_sort(t_deque *pdeque)
{
	if ((pdeque->a->front->value) > (pdeque->a->front->next->value))
		sa(pdeque, 1);
}

void	three_element_sort(t_deque *pdeque)
{
	int	top;
	int	mid;
	int	bottom;

	top = pdeque->a->front->value;
	mid = pdeque->a->front->next->value;
	bottom = pdeque->a->front->next->next->value;
	if (top < mid && mid > bottom && top < bottom)
	{
		sa(pdeque, 1);
		ra(pdeque, 1);
	}
	else if (top > mid && mid < bottom && top < bottom)
		sa(pdeque, 1);
	else if (top < mid && mid > bottom && top > bottom)
		rra(pdeque, 1);
	else if (top > mid && mid < bottom && top > bottom)
		ra(pdeque, 1);
	else if (top > mid && mid > bottom && top > bottom)
	{
		sa(pdeque, 1);
		rra(pdeque, 1);
	}
}

void	four_element_sort(t_deque *pdeque)
{
	int	min_idx;

	min_idx = get_min_idx(pdeque);
	if (min_idx == 1)
		ra(pdeque, 1);
	else if (min_idx == 2)
	{
		ra(pdeque, 1);
		ra(pdeque, 1);
	}
	else if (min_idx == 3)
		rra(pdeque, 1);
	pb(pdeque, 1);
	three_element_sort(pdeque);
	pa(pdeque, 1);
}

void	five_element_sort(t_deque *pdeque)
{
	int	min_idx;

	min_idx = get_min_idx(pdeque);
	if (min_idx == 1)
		ra(pdeque, 1);
	else if (min_idx == 2)
	{
		ra(pdeque, 1);
		ra(pdeque, 1);
	}
	else if (min_idx == 3)
	{
		rra(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (min_idx == 4)
		rra(pdeque, 1);
	pb(pdeque, 1);
	four_element_sort(pdeque);
	pa(pdeque, 1);
}

void	six_element_sort(t_deque *pdeque)
{
	int	min_idx;

	min_idx = get_min_idx(pdeque);
	if (min_idx == 1)
		ra(pdeque, 1);
	else if (min_idx == 2 || min_idx == 3)
	{
		ra(pdeque, 1);
		ra(pdeque, 1);
	}
	if (min_idx == 3)
		ra(pdeque, 1);
	else if (min_idx == 4)
	{
		rra(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (min_idx == 5)
		rra(pdeque, 1);
	pb(pdeque, 1);
	five_element_sort(pdeque);
	pa(pdeque, 1);
}
