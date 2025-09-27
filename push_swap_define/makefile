NAME = push_swap

SRCDIR = src
INCDIR = include
LIBDIR = src/lib
UTILDIR = src/utils
OPDIR = src/operations
ALGDIR = src/algorithm
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/push_swap.c \
       $(OPDIR)/push.c \
       $(OPDIR)/swap.c \
       $(OPDIR)/rotate.c \
       $(OPDIR)/reverse.c \
       $(ALGDIR)/small.c \
       $(ALGDIR)/turk.c \
       $(ALGDIR)/turk2.c \
       $(ALGDIR)/turk3.c \
       $(ALGDIR)/algorithm.c \
       $(UTILDIR)/stack_utils.c \
       $(UTILDIR)/normalize.c \
       $(UTILDIR)/parse.c \
       $(UTILDIR)/error.c \
       $(LIBDIR)/ft_atoi.c \
       $(LIBDIR)/ft_isdigit.c \
       $(LIBDIR)/ft_putstr_fd.c \
       $(LIBDIR)/ft_split.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Corrige a compilação de arquivos em subpastas
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OPDIR)/%.o: $(OPDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ALGDIR)/%.o: $(ALGDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILDIR)/%.o: $(UTILDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
