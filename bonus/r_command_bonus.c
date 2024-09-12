/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_command_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:27:02 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 17:10:53 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_deque *pdeque, int io)
{
	t_node	*a_top;

	a_top = pop_front(pdeque->a);
	if (a_top == NULL)
		return (FALSE);
	if (push_rear(pdeque->a, *a_top) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "ra\n", 3);
	free(a_top);
	return (TRUE);
}

int	rb(t_deque *pdeque, int io)
{
	t_node	*b_top;

	b_top = pop_front(pdeque->b);
	if (b_top == NULL)
		return (FALSE);
	if (push_rear(pdeque->b, *b_top) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "rb\n", 3);
	free(b_top);
	return (TRUE);
}

int	rr(t_deque *pdeque, int io)
{
	ra(pdeque, -1);
	rb(pdeque, -1);
	if (io != -1)
		write(io, "rr\n", 3);
	return (TRUE);
}
