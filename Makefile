# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:01:31 by linhnguy          #+#    #+#              #
#    Updated: 2024/02/13 22:01:24 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpush.a
LIBFT = libft.a
LIBFTDIR = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SRCS =	get_list.c array_utils.c list_utils.c make_list.c commands.c sort.c \
		commands2.c set_node_a.c set_node_b.c set_node_utils.c				\
		sort_utils.c algo_a_utils.c algo_b_utils.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) push_swap.c $(NAME) -o push_swap
	@echo "Program Made"

debug: re
	@$(CC) $(CFLAGS) -fsanitize=address -g3 push_swap.c $(NAME) -o push_swap

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) push_swap a.out
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully Cleaned"

re: fclean all
