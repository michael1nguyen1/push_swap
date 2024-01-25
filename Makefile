# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:01:31 by linhnguy          #+#    #+#              #
#    Updated: 2024/01/25 17:38:48 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpush.a
LIBFT = libft.a
LIBFTDIR = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ft_get_list.c push_swap_utils.c push_swap_utils2.c ft_make_list.c ft_commands.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

run: re
	@cc main.c $(NAME) -o push_swap
	@./push_swap 1 2 3 4 5

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully cleaned the project"

re: fclean all