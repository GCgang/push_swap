/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:53:48 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 17:11:11 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

long long	ft_atoi(char *str)
{
	long long	result;
	long long	sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (3000000000);
	while (ft_isdigit(*str) == TRUE)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (ft_isdigit(*str) == FALSE && *str != '\0')
		return (3000000000);
	return (result * sign);
}

void	return_ctl(int flag, t_deque *pdeque)
{
	if (flag == 0)
	{
		free(pdeque->num_array);
		free(pdeque);
		exit(0);
	}
	else if (flag == 1)
	{
		free(pdeque->num_array);
		free(pdeque);
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (flag == 2)
	{
		finallize(pdeque);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	get_min_idx(t_deque *pdeque)
{
	t_node	*n_node;
	int		min_idx;
	int		min_value;
	int		i;

	n_node = pdeque->a->front;
	min_value = pdeque->a->front->value;
	min_idx = 0;
	i = -1;
	while (++i < pdeque->a->element_count - 1)
	{
		n_node = n_node->next;
		if (min_value > n_node->value)
		{
			min_idx = i + 1;
			min_value = n_node->value;
		}
	}
	return (min_idx);
}

int	get_max_idx(t_deque *pdeque)
{
	t_node	*n_node;
	int		max_idx;
	int		max_value;
	int		i;

	n_node = pdeque->a->front;
	max_value = pdeque->a->front->value;
	max_idx = 0;
	i = -1;
	while (++i < pdeque->a->element_count - 1)
	{
		n_node = n_node->next;
		if (max_value < n_node->value)
		{
			max_idx = i + 1;
			max_value = n_node->value;
		}
	}
	return (max_idx);
}
