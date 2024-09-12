/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_deque.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:01:09 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 19:56:38 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_DEQUE_H
# define LINKED_DEQUE_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ASCENDING 0
# define DESCENDING 1

typedef struct s_deque_node
{
	int					value;
	struct s_deque_node	*next;
	struct s_deque_node	*prev;
}	t_node;

typedef struct s_linked_deque
{
	int		element_count;
	t_node	*front;
	t_node	*rear;
}	t_linked_deque;

typedef struct s_deque
{
	t_linked_deque	*a;
	t_linked_deque	*b;
	int				*num_array;
	int				tot_cnt;
}	t_deque;

t_deque			*setting(void);// main
void			initialize(t_deque *pdeque);
void			parsing(int argc, char **argv, t_deque *pdeque);
void			finallize(t_deque *pdeque);
t_node			*pop_front(t_linked_deque *deque);// linked_deque
t_node			*pop_rear(t_linked_deque *deque);
int				push_front(t_linked_deque *deque, t_node element);
int				push_rear(t_linked_deque *deque, t_node element);
t_linked_deque	*create_deque(t_deque *pdeque, int tot_cnt);
void			delete_deque(t_linked_deque *deque);// linked_deque_utils
int				isdeque_empty(t_linked_deque *deque);
int				pa(t_deque *pdeque, int io);// p command
int				pb(t_deque *pdeque, int io);
int				ra(t_deque *pdeque, int io);// r command
int				rb(t_deque *pdeque, int io);
int				rr(t_deque *pdeque, int io);// rr command
int				rra(t_deque *pdeque, int io);
int				rrb(t_deque *pdeque, int io);
int				rrr(t_deque *pdeque, int io);
int				sa(t_deque *pdeque, int io);// ss command
int				sb(t_deque *pdeque, int io);
int				ss(t_deque *pdeque, int io);
void			*free_str_arr(char **str_arr);// split
size_t			ft_word_cnt(const char *str, char charset, int *tot_cnt);
size_t			get_word_len(const char *str, char charset);
char			*put_word(const char *str, char charset);
char			**ft_split(const char *str, char charset, int *tot_cnt);
int				ft_isdigit(int c);// util
long long		ft_atoi(char *str);
void			return_ctl(int flag, t_deque *pdeque);
int				get_min_idx(t_deque *pdeque);
int				get_max_idx(t_deque *pdeque);
int				numarr_sorted(t_deque *pdeque);// validation
int				duplicated(t_deque *pdeque);
int				is_sorted(t_linked_deque *a_or_b);
void			num_validation(t_deque *pdeque);
void			check_arg(int argc, char **argv);
void			small_sort(t_deque *pdeque);// merge_sort
void			divide(t_deque *pdeque);
void			merge_sort(t_deque *pdeque);
void			six_element_sort(t_deque *pdeque);// small_sort
void			five_element_sort(t_deque *pdeque);
void			four_element_sort(t_deque *pdeque);
void			three_element_sort(t_deque *pdeque);
void			two_element_sort(t_deque *pdeque);
void			get_triangle_size(t_deque *pdeque, int depth, \
								char deque);// divide
int				get_order(int idx);
int				power(int nb, int power);
int				get_depth(t_deque *pdeque);
void			triangle_to_b(t_deque *pdeque, int order, int triangle_size);
void			set_n(t_deque *pdeque, int *n, int cnt);// triangle_to_b
int				get_n_max(int *n, int cnt);
int				get_n_min(int *n, int cnt);
void			ascending_order_to_b(t_deque *pdeque, int triangle_size);
void			descending_order_to_b(t_deque *pdeque, int triangle_size);
void			ascending_six_to_b(t_deque *pdeque);// ascending_order_to_b
void			ascending_five_to_b(t_deque *pdeque);
void			ascending_four_to_b(t_deque *pdeque);
void			ascending_three_to_b(t_deque *pdeque);
void			ascending_two_to_b(t_deque *pdeque);
void			decending_six_to_b(t_deque *pdeque);// descending_order_to_b
void			decending_five_to_b(t_deque *pdeque);
void			decending_four_to_b(t_deque *pdeque);
void			decending_three_to_b(t_deque *pdeque);
void			decending_two_to_b(t_deque *pdeque);
void			a6_sa_pb_rra(t_deque *pdeque);// div_six
void			a6_ra_sa_pb_rra_rra(t_deque *pdeque);
void			a6_rra_rra_rra_pb_ra_ra(t_deque *pdeque);
void			a6_rra_rra_pb_ra(t_deque *pdeque);
void			a6_rra_pb(t_deque *pdeque);
void			a5_sa_pb(t_deque *pdeque);// div_five
void			a5_ra_sa_pb_rra(t_deque *pdeque);
void			a5_rra_rra_pb_ra_ra(t_deque *pdeque);
void			a5_rra_pb_ra(t_deque *pdeque);
void			a4_pb_rra(t_deque *pdeque);// div_four
void			a4_sa_pb_rra(t_deque *pdeque);
void			a4_rra_rra_pb_ra(t_deque *pdeque);
void			a4_rra_pb(t_deque *pdeque);
void			merging(t_deque *pdeque);//merging
int				get_min_max(int *n, int *limit, int order);
void			setting_n(t_deque *pdeque, int *n, int *limit, char a_or_b);
void			is_sorted_b(t_deque *pdeque);
void			a_to_b_push(t_deque *pdeque, int max_triangle);// atob
void			a_to_b(t_deque *pdeque, int max_triangle);
void			a_to_b_merge(t_deque *pdeque, int max_triangle, \
							int order, int i);
void			pb_rra_pb_rrb(t_deque *pdeque, int min_max, int *n, int*limit);
void			b_to_a_push(t_deque *pdeque, int max_triangle);// btoa
void			b_to_a(t_deque *pdeque, int max_triangle);
void			b_to_a_mege(t_deque *pdeque, int max_triangle, \
							int order, int i);
void			rra_pa_rrb_pa(t_deque *pdeque, int min_max, int *n, int*limit);

#endif
