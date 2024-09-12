/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descending_order_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:15:02 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 11:16:23 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	decending_six_to_b(t_deque *pdeque)
{
	int	n[6];
	int	min;

	set_n(pdeque, n, 6);
	min = get_n_min(n, 6);
	if (min == n[0])
	{
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (min == n[1])
		a6_sa_pb_rra(pdeque);
	else if (min == n[2])
		a6_ra_sa_pb_rra_rra(pdeque);
	else if (min == n[3])
		a6_rra_rra_rra_pb_ra_ra(pdeque);
	else if (min == n[4])
		a6_rra_rra_pb_ra(pdeque);
	else if (min == n[5])
		a6_rra_pb(pdeque);
	decending_five_to_b(pdeque);
}

void	decending_five_to_b(t_deque *pdeque)
{
	int	n[5];
	int	min;

	set_n(pdeque, n, 5);
	min = get_n_min(n, 5);
	if (min == n[0])
		pb(pdeque, 1);
	else if (min == n[1])
		a5_sa_pb(pdeque);
	else if (min == n[2])
		a5_ra_sa_pb_rra(pdeque);
	else if (min == n[3])
		a5_rra_rra_pb_ra_ra(pdeque);
	else if (min == n[4])
		a5_rra_pb_ra(pdeque);
	decending_four_to_b(pdeque);
}

void	decending_four_to_b(t_deque *pdeque)
{
	int	n[4];
	int	min;

	set_n(pdeque, n, 4);
	min = get_n_min(n, 4);
	if (min == n[0])
		a4_pb_rra(pdeque);
	else if (min == n[1])
		a4_sa_pb_rra(pdeque);
	else if (min == n[2])
		a4_rra_rra_pb_ra(pdeque);
	else if (min == n[3])
		a4_rra_pb(pdeque);
	decending_three_to_b(pdeque);
}

void	decending_three_to_b(t_deque *pdeque)
{
	int	n[3];
	int	min;

	set_n(pdeque, n, 3);
	min = get_n_min(n, 3);
	if (min == n[0])
	{
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (min == n[1])
	{
		sa(pdeque, 1);
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (min == n[2])
	{
		rra(pdeque, 1);
		pb(pdeque, 1);
	}
	decending_two_to_b(pdeque);
}

void	decending_two_to_b(t_deque *pdeque)
{
	if (pdeque->a->front->value > pdeque->a->front->next->value)
		sa(pdeque, 1);
	pb(pdeque, 1);
	pb(pdeque, 1);
}
