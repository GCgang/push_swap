# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 16:25:55 by hyeoan            #+#    #+#              #
#    Updated: 2023/02/19 19:18:01 by hyeoan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
B_NAME = checker
SOURCES = main.c \
			linked_deque.c \
			linked_deque_utils.c \
			merge_sort.c \
			small_sort.c \
			divide.c \
			ascending_order_to_b.c \
			descending_order_to_b.c \
			div_six.c \
			div_five.c \
			div_four.c \
			split.c \
			util.c \
			validation.c \
			merging.c \
			triangle_to_b.c \
			a_to_b.c \
			b_to_a.c \
			p_command.c \
			r_command.c \
			rr_command.c \
			s_command.c \

B_SOURCES = ./bonus/main.c \
			./bonus/checker.c \
			./bonus/linked_deque.c \
			./bonus/linked_deque_utils.c \
			./bonus/get_next_line.c \
			./bonus/get_next_line_utils.c \
			./bonus/split_bonus.c \
			./bonus/util_bonus.c \
			./bonus/validation_bonus.c \
			./bonus/p_command_bonus.c \
			./bonus/r_command_bonus.c \
			./bonus/rr_command_bonus.c \
			./bonus/s_command_bonus.c \

OBJS = $(SOURCES:.c=.o)
B_OBJS = $(B_SOURCES:.c=.o)	
	
ifdef WITH_BONUS
	OBJECTS = $(B_OBJS)
	PROGRAM = $(B_NAME)
else
	OBJECTS = $(OBJS)
	PROGRAM = $(NAME)
endif

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROGRAM)

bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJS) $(B_OBJS)

fclean : clean
	rm -rf $(NAME) $(B_NAME) 

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus