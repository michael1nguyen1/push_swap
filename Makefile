# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:01:31 by linhnguy          #+#    #+#              #
#    Updated: 2024/02/09 16:21:00 by linhnguy         ###   ########.fr        #
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
	./push_swap 17 -611 -644 766 757 -486 -351 544 -470 900 767 -873 -11 -504 359 51 608 278 -187 395 -824 -334 -883 633 -895 347 197 -994 -775 -953 366 -205 41 -507 671 554 183 691 -529 780 -657 393 135 -665 -283 -593 714 -86 870 -863

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