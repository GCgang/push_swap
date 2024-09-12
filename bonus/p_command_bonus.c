/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_command_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:27:00 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 19:44:14 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pa(t_deque *pdeque, int io)
{
	t_node	*b_top;

	b_top = pop_front(pdeque->b);
	if (b_top == NULL)
		return (FALSE);
	if (push_front(pdeque->a, *b_top) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "pa\n", 3);
	free(b_top);
	return (TRUE);
}

int	pb(t_deque *pdeque, int io)
{
	t_node	*a_top;

	a_top = pop_front(pdeque->a);
	if (a_top == NULL)
		return (FALSE);
	if (push_front(pdeque->b, *a_top) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "pb\n", 3);
	free(a_top);
	return (TRUE);
}
