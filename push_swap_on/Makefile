NAME = push_swap
SRCDIR = src
INCDIR = includes
LIBDIR = libft
UTILDIR = src/utils
OPDIR = src/operations
ALGDIR = src/algorithms

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/push_swap.c \
       $(OPDIR)/push.c \
       $(OPDIR)/swap.c \
       $(OPDIR)/rotate.c \
       $(OPDIR)/reverse_rotate.c \
       $(ALGDIR)/small_sort.c \
       $(ALGDIR)/turk_algorithm.c \
       $(ALGDIR)/cost_calculation.c \
       $(UTILDIR)/parsing.c \
       $(UTILDIR)/stack_utils.c \
       $(UTILDIR)/normalize.c \
       $(UTILDIR)/error_handling.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR) -I$(LIBDIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/libft.a -o $(NAME)

%.o: %.c $(INCDIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
