CFLAGS = -Wall -Wextra -Werror -I. -g
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = push_swap

CFILES = push_swap.c operations.c rec_sorting.c non_rec_sorting.c parser.c normalisation.c utils.c utils2.c
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

re: fclean all

.PHONY: all clean fclean re
