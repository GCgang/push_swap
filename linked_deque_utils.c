/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_deque_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:18:45 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/18 15:19:04 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

void	delete_deque(t_linked_deque *deque)
{
	t_node	*del_node;

	del_node = deque->front;
	while (del_node != NULL)
	{
		free(del_node);
		del_node = del_node->next;
	}
	deque->element_count = 0;
	deque->front = NULL;
	deque->rear = NULL;
	free (deque);
}

int	isdeque_empty(t_linked_deque *deque)
{
	if (deque->element_count == 0)
		return (TRUE);
	return (FALSE);
}
