/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_order_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:14:32 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 11:16:36 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	ascending_six_to_b(t_deque *pdeque)
{
	int	n[6];
	int	max;

	set_n(pdeque, n, 6);
	max = get_n_max(n, 6);
	if (max == n[0])
	{
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (max == n[1])
		a6_sa_pb_rra(pdeque);
	else if (max == n[2])
		a6_ra_sa_pb_rra_rra(pdeque);
	else if (max == n[3])
		a6_rra_rra_rra_pb_ra_ra(pdeque);
	else if (max == n[4])
		a6_rra_rra_pb_ra(pdeque);
	else if (max == n[5])
		a6_rra_pb(pdeque);
	ascending_five_to_b(pdeque);
}

void	ascending_five_to_b(t_deque *pdeque)
{
	int	n[5];
	int	max;

	set_n(pdeque, n, 5);
	max = get_n_max(n, 5);
	if (max == n[0])
		pb(pdeque, 1);
	else if (max == n[1])
		a5_sa_pb(pdeque);
	else if (max == n[2])
		a5_ra_sa_pb_rra(pdeque);
	else if (max == n[3])
		a5_rra_rra_pb_ra_ra(pdeque);
	else if (max == n[4])
		a5_rra_pb_ra(pdeque);
	ascending_four_to_b(pdeque);
}

void	ascending_four_to_b(t_deque *pdeque)
{
	int	n[4];
	int	max;

	set_n(pdeque, n, 4);
	max = get_n_max(n, 4);
	if (max == n[0])
		a4_pb_rra(pdeque);
	else if (max == n[1])
		a4_sa_pb_rra(pdeque);
	else if (max == n[2])
		a4_rra_rra_pb_ra(pdeque);
	else if (max == n[3])
		a4_rra_pb(pdeque);
	ascending_three_to_b(pdeque);
}

void	ascending_three_to_b(t_deque *pdeque)
{
	int	n[3];
	int	max;

	set_n(pdeque, n, 3);
	max = get_n_max(n, 3);
	if (max == n[0])
	{
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (max == n[1])
	{
		sa(pdeque, 1);
		pb(pdeque, 1);
		rra(pdeque, 1);
	}
	else if (max == n[2])
	{
		rra(pdeque, 1);
		pb(pdeque, 1);
	}
	ascending_two_to_b(pdeque);
}

void	ascending_two_to_b(t_deque *pdeque)
{
	if (pdeque->a->front->value < pdeque->a->front->next->value)
		sa(pdeque, 1);
	pb(pdeque, 1);
	pb(pdeque, 1);
}
