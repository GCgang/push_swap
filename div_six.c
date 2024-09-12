/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_six.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:22:28 by jun               #+#    #+#             */
/*   Updated: 2023/02/17 14:21:32 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	a6_sa_pb_rra(t_deque *pdeque)
{
	sa(pdeque, 1);
	pb(pdeque, 1);
	rra(pdeque, 1);
}

void	a6_ra_sa_pb_rra_rra(t_deque *pdeque)
{
	ra(pdeque, 1);
	sa(pdeque, 1);
	pb(pdeque, 1);
	rra(pdeque, 1);
	rra(pdeque, 1);
}

void	a6_rra_rra_rra_pb_ra_ra(t_deque *pdeque)
{
	rra(pdeque, 1);
	rra(pdeque, 1);
	rra(pdeque, 1);
	pb(pdeque, 1);
	ra(pdeque, 1);
	ra(pdeque, 1);
}

void	a6_rra_rra_pb_ra(t_deque *pdeque)
{
	rra(pdeque, 1);
	rra(pdeque, 1);
	pb(pdeque, 1);
	ra(pdeque, 1);
}

void	a6_rra_pb(t_deque *pdeque)
{
	rra(pdeque, 1);
	pb(pdeque, 1);
}
