NAME        = pushswap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
CFLAGS     += -Iincludes -Iincludes/gnl -Iincludes/ft_printf

SRCS        = $(shell find src -name "*.c")
SRCS       += $(shell find includes/ft_printf -name "*.c")
SRCS       += $(shell find includes/gnl -name "*.c")

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation complete!"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
