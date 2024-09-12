/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:55:55 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 20:28:29 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_command(t_deque *pdeque, char	*command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(pdeque, -1);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(pdeque, -1);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(pdeque, -1);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(pdeque, -1);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(pdeque, -1);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(pdeque, -1);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(pdeque, -1);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(pdeque, -1);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(pdeque, -1);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(pdeque, -1);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(pdeque, -1);
	else
		return (-1);
	return (1);
}

void	checker(t_deque *pdeque)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			return ;
		if (check_command(pdeque, command) == -1)
		{
			free(command);
			return_ctl(2, pdeque);
		}
		free(command);
	}
}

void	check_sorted(t_deque *pdeque)
{
	if (isdeque_empty(pdeque->a) == FALSE)
	{
		if ((is_sorted(pdeque->a) == TRUE) && \
		(isdeque_empty(pdeque->b) == TRUE))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
