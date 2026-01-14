NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include -g
RM = rm -f
MAIN = src/main.c

PARSE = src/parse/create_stack.c	\
		src/parse/list_checks.c		\
		src/parse/arg_check.c		\

MOVES = src/moves/push.c	\
		src/moves/swap.c	\
		src/moves/rotate.c	\
		src/moves/reverse.c	\

SORT = src/sort/sort.c

UTILS = src/utils/ft_atoi.c		\
		src/utils/ft_split.c	\
		src/utils/ft_substr.c	\
		src/utils/ft_strlen.c	\
		src/utils/ft_strdup.c	\
		src/utils/list_clear.c	\

HEADERS = include/push_wap.h
SOURCES = $(MAIN) $(MOVES) $(PARSE) $(UTILS) $(SORT)
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(OBJECTS) Makefile

$(NAME): $(DEPENDS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

tst: MAIN = src/test.c
tst: $(NAME)

dbg: MAIN = src/debug.c
dbg: $(NAME)

fs: $(OBJECTS) Makefile
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -fsanitize=address

%.o: %.c Makefile $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

r: $(NAME)
	./push_swap "1 3 2"

all: $(NAME) clean

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
