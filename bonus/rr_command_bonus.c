/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:43:57 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 17:10:56 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_deque *pdeque, int io)
{
	t_node	*a_bottom;

	a_bottom = pop_rear(pdeque->a);
	if (a_bottom == NULL)
		return (FALSE);
	if (push_front(pdeque->a, *a_bottom) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "rra\n", 4);
	free(a_bottom);
	return (TRUE);
}

int	rrb(t_deque *pdeque, int io)
{
	t_node	*b_bottom;

	b_bottom = pop_rear(pdeque->b);
	if (b_bottom == NULL)
		return (FALSE);
	if (push_front(pdeque->b, *b_bottom) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(1, "rrb\n", 4);
	free(b_bottom);
	return (TRUE);
}

int	rrr(t_deque *pdeque, int io)
{
	rra(pdeque, -1);
	rrb(pdeque, -1);
	if (io != -1)
		write(io, "rrr\n", 4);
	return (TRUE);
}
