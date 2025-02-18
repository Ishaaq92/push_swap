# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:50:21 by isahmed           #+#    #+#              #
#    Updated: 2025/02/18 13:18:00 by isahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra  -I. -fsanitize=address
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = push_swap

CFILES = push_swap.c operations.c operations2.c operations3.c operations4.c rec_sorting.c non_rec_sorting.c parser.c normalisation.c utils.c utils2.c base_sort.c
OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)

FT_PRINTF = ft_printf/libftprintf.a 

DIRS = $(ODIR)

all: $(BINARY)

$(DIRS):
	@mkdir -p $@

$(BINARY): $(OBJECTS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@
$(FT_PRINTF): 
	@make --no-print-directory -C ft_printf 

$(ODIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	make -C ft_printf fclean
	rm -rf $(OBJECTS)/*
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re
