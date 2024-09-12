/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:18:11 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 19:46:51 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_deque	*setting(void)
{
	t_deque	*pdeque;

	pdeque = (t_deque *)malloc(sizeof(t_deque));
	if (pdeque == NULL)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	pdeque->num_array = (int *)malloc(sizeof(int) * INT_MAX);
	if (pdeque->num_array == NULL)
		return_ctl(1, pdeque);
	pdeque->a = NULL;
	pdeque->b = NULL;
	pdeque->tot_cnt = 0;
	return (pdeque);
}

void	initialize(t_deque *pdeque)
{
	pdeque->a = create_deque(pdeque, pdeque->tot_cnt);
	if (pdeque->a == NULL)
		return_ctl(1, pdeque);
	pdeque->b = create_deque(pdeque, 0);
	if (pdeque->b == NULL)
	{
		free(pdeque->a);
		return_ctl(1, pdeque);
	}
}

void	parsing(int argc, char **argv, t_deque *pdeque)
{
	char		**array;
	long long	num;
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		array = ft_split(argv[i], ' ', &pdeque->tot_cnt);
		if (array == NULL)
			return_ctl(1, pdeque);
		j = -1;
		while (array[++j] != NULL)
		{
			num = ft_atoi(array[j]);
			if (num < INT_MIN || INT_MAX < num)
				return_ctl(1, pdeque);
			pdeque->num_array[j + k] = (int)num;
			free(array[j]);
		}
		k = pdeque->tot_cnt;
		free(array);
	}
}

void	finallize(t_deque *pdeque)
{
	delete_deque(pdeque->a);
	free(pdeque->b);
	free(pdeque->num_array);
	free(pdeque);
}

int	main(int argc, char **argv)
{
	t_deque	*pdeque;

	check_arg(argc, argv);
	pdeque = setting();
	parsing(argc, argv, pdeque);
	num_validation(pdeque);
	initialize(pdeque);
	checker(pdeque);
	check_sorted(pdeque);
	finallize(pdeque);
	return (0);
}
