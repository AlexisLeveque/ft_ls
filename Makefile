# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 20:20:16 by aleveque          #+#    #+#              #
#    Updated: 2017/06/13 19:40:35 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ft_ls

SRCDIR = src

OBJDIR = obj

SRC = main.c parsing.c error.c

OBJ = $(SRC:.c=.o)

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

all:libcomp  $(OBJDIR) $(NAME)

re: fclean all

libcomp:
	@make -C libft/
	@make -C ft_printf/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $^

$(OBJDIR):
	@echo "\033[1;32mcompiling obj"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling exec"
	@$(CC) -o $@ $^ $(LIBFT) $(PRINTF)

clean:
	@echo "\033[1;31mcleaning obj"
	@rm -rf $(OBJDIR)
	@make clean -C libft/
	@make clean -C ft_printf/

fclean:
	@echo "\033[1;31mcleaning exec"
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)

test:
		@$(CC) -o ft_ls src/test.c $(LIBFT)
