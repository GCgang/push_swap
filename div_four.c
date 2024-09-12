/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_four.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:23:20 by jun               #+#    #+#             */
/*   Updated: 2023/02/17 14:21:05 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	a4_pb_rra(t_deque *pdeque)
{
	pb(pdeque, 1);
	rra(pdeque, 1);
}

void	a4_sa_pb_rra(t_deque *pdeque)
{
	sa(pdeque, 1);
	pb(pdeque, 1);
	rra(pdeque, 1);
}

void	a4_rra_rra_pb_ra(t_deque *pdeque)
{
	rra(pdeque, 1);
	rra(pdeque, 1);
	pb(pdeque, 1);
	ra(pdeque, 1);
}

void	a4_rra_pb(t_deque *pdeque)
{
	rra(pdeque, 1);
	pb(pdeque, 1);
}
