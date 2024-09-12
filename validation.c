/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:58:58 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 16:55:50 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_deque.h"

int	numarr_sorted(t_deque *pdeque)
{
	int	i;

	i = -1;
	while (++i < pdeque->tot_cnt - 1)
	{
		if (pdeque->num_array[i] > pdeque->num_array[i + 1])
			return (FALSE);
	}
	return (TRUE);
}

int	is_sorted(t_linked_deque *a_or_b)
{
	int		i;
	int		val;
	t_node	*node;

	i = -1;
	node = a_or_b->front;
	val = node->value;
	while (++i < a_or_b->element_count - 1)
	{
		node = node->next;
		if (val > node->value)
			return (FALSE);
		val = node->value;
	}
	return (TRUE);
}

int	duplicated(t_deque *pdeque)
{
	int	i;
	int	j;
	int	flag;
	int	*check_array;

	i = -1;
	check_array = (int *)malloc(sizeof(int) * pdeque->tot_cnt);
	if (check_array == NULL)
		return_ctl(1, pdeque);
	while (++i < pdeque->tot_cnt)
		check_array[i] = pdeque->num_array[i];
	i = -1;
	while (++i < pdeque->tot_cnt)
	{
		j = -1;
		flag = 0;
		while (++j < pdeque->tot_cnt)
		{
			if (pdeque->num_array[i] == check_array[j])
				flag++;
			if (flag >= 2)
				return (free(check_array), TRUE);
		}
	}
	return (free(check_array), FALSE);
}

void	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		exit(1);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}

void	num_validation(t_deque *pdeque)
{
	if (duplicated(pdeque) == TRUE)
		return_ctl(1, pdeque);
	if (numarr_sorted(pdeque) == TRUE)
		return_ctl(0, pdeque);
}
