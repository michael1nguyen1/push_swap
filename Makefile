# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:01:31 by linhnguy          #+#    #+#              #
#    Updated: 2024/02/06 16:13:02 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpush.a
LIBFT = libft.a
LIBFTDIR = libft
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_get_list.c array_utils.c list_utils.c ft_make_list.c commands.c ft_sort.c commands2.c ft_print_intlist.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

run: re
	@$(CC) main.c $(NAME) -o push_swap
	./push_swap 900 700 -1 5 6 7 12 844 -99

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) push_swap a.out
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully cleaned the project"

re: fclean all