/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:03:52 by hyeoan            #+#    #+#             */
/*   Updated: 2023/02/19 20:00:43 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647

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

typedef struct s_node
{
	int				fd;
	char			*back_up;
	struct s_node	*next;
}	t_file_node;

typedef struct s_list
{
	t_file_node	*tail;
	t_file_node	*before;
	t_file_node	*current;
	size_t		total_fd;
}	t_list;

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
int				duplicated(t_deque *pdeque);// validation
int				is_sorted(t_linked_deque *a_or_b);
void			num_validation(t_deque *pdeque);
void			check_arg(int argc, char **argv);
int				check_command(t_deque *pdeque, char	*command);// checker
void			checker(t_deque *pdeque);
void			check_sorted(t_deque *pdeque);
int				ft_strcmp(char *s1, char *s2);
char			*get_next_line(int fd);// gnl
int				find_node(t_list *file_list, int fd);
int				add_node(t_list *file_list, int fd);
char			*read_file(t_list *file_list, char *buf);
char			*make_line(t_list *file_list);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
void			remove_list(t_list *file_list);

#endif