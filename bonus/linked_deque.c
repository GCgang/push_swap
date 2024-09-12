/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:01:11 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 16:40:46 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_linked_deque	*create_deque(t_deque *pdeque, int tot_cnt)
{
	t_linked_deque	*deque;
	t_node			*node;
	int				i;

	i = 0;
	deque = (t_linked_deque *)malloc(sizeof(t_linked_deque));
	if (deque == NULL)
		return (NULL);
	deque->element_count = 0;
	while (i < tot_cnt)
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (node == NULL)
			return (free(deque), NULL);
		node->value = pdeque->num_array[i++];
		if (push_rear(deque, *node) == FALSE)
		{
			delete_deque(deque);
			return (NULL);
		}
		free(node);
	}
	return (deque);
}

int	push_front(t_linked_deque *deque, t_node element)
{
	t_node	*deque_node;

	deque_node = (t_node *)malloc(sizeof(t_node));
	if (deque_node == NULL)
		return (FALSE);
	*deque_node = element;
	if (deque->element_count == 0)
	{
		deque->rear = deque_node;
		deque_node->prev = NULL;
		deque_node->next = deque->front;
		deque->front = deque_node;
	}
	else
	{
		deque_node->prev = NULL;
		deque_node->next = deque->front;
		deque->front->prev = deque_node;
		deque->front = deque_node;
	}
	deque->element_count++;
	return (TRUE);
}

int	push_rear(t_linked_deque *deque, t_node element)
{
	t_node	*deque_node;

	deque_node = (t_node *)malloc(sizeof(t_node));
	if (deque_node == NULL)
		return (FALSE);
	*deque_node = element;
	if (deque->element_count == 0)
	{
		deque->front = deque_node;
		deque_node->next = NULL;
		deque_node->prev = deque->rear;
		deque->rear = deque_node;
	}
	else
	{
		deque_node->next = NULL;
		deque_node->prev = deque->rear;
		deque->rear->next = deque_node;
		deque->rear = deque_node;
	}
	deque->element_count++;
	return (TRUE);
}

t_node	*pop_front(t_linked_deque *deque)
{
	t_node	*del_node;

	if (isdeque_empty(deque) == FALSE)
	{
		if (deque->element_count == 1)
		{
			del_node = deque->front;
			del_node->next = NULL;
			deque->front = NULL;
			deque->rear = NULL;
		}
		else
		{
			del_node = deque->front;
			deque->front = deque->front->next;
			deque->front->prev = NULL;
			del_node->next = NULL;
		}
		deque->element_count--;
		return (del_node);
	}
	return (NULL);
}

t_node	*pop_rear(t_linked_deque *deque)
{
	t_node	*del_node;

	if (isdeque_empty(deque) == FALSE)
	{
		if (deque->element_count == 1)
		{
			del_node = deque->rear;
			del_node->prev = NULL;
			deque->front = NULL;
			deque->rear = NULL;
		}
		else
		{
			del_node = deque->rear;
			deque->rear = deque->rear->prev;
			deque->rear->next = NULL;
			del_node->prev = NULL;
		}
		deque->element_count--;
		return (del_node);
	}
	return (NULL);
}
