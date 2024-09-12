/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:22:44 by jun               #+#    #+#             */
/*   Updated: 2023/02/17 14:20:46 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	a5_sa_pb(t_deque *pdeque)
{
	sa(pdeque, 1);
	pb(pdeque, 1);
}

void	a5_ra_sa_pb_rra(t_deque *pdeque)
{
	ra(pdeque, 1);
	sa(pdeque, 1);
	pb(pdeque, 1);
	rra(pdeque, 1);
}

void	a5_rra_rra_pb_ra_ra(t_deque *pdeque)
{
	rra(pdeque, 1);
	rra(pdeque, 1);
	pb(pdeque, 1);
	ra(pdeque, 1);
	ra(pdeque, 1);
}

void	a5_rra_pb_ra(t_deque *pdeque)
{
	rra(pdeque, 1);
	pb(pdeque, 1);
	ra(pdeque, 1);
}
