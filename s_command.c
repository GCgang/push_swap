/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:27:07 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 14:16:39 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

int	sa(t_deque *pdeque, int io)
{
	t_node	*a_top;
	t_node	*a_top_next;

	if (pdeque->a->element_count < 2)
		return (FALSE);
	a_top = pop_front(pdeque->a);
	a_top_next = pop_front(pdeque->a);
	if (push_front(pdeque->a, *a_top) == FALSE)
		return_ctl(2, pdeque);
	if (push_front(pdeque->a, *a_top_next) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "sa\n", 3);
	free(a_top);
	free(a_top_next);
	return (TRUE);
}

int	sb(t_deque *pdeque, int io)
{
	t_node	*b_top;
	t_node	*b_top_next;

	if (pdeque->b->element_count < 2)
		return (FALSE);
	b_top = pop_front(pdeque->b);
	b_top_next = pop_front(pdeque->b);
	if (push_front(pdeque->b, *b_top) == FALSE)
		return_ctl(2, pdeque);
	if (push_front(pdeque->b, *b_top_next) == FALSE)
		return_ctl(2, pdeque);
	if (io != -1)
		write(io, "sb\n", 3);
	free(b_top);
	free(b_top_next);
	return (TRUE);
}

int	ss(t_deque *pdeque, int io)
{
	sa(pdeque, -1);
	sb(pdeque, -1);
	if (io != -1)
		write(io, "ss\n", 3);
	return (TRUE);
}
