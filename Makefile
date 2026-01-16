NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include -g
RM = rm -f
MAIN = src/main.c
TST = test/num_gen.c

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
		src/utils/free_array.c	\

HEADERS = include/push_wap.h
SOURCES = $(MAIN) $(MOVES) $(PARSE) $(UTILS) $(SORT)
OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(OBJECTS) Makefile

TEST_SRC = $(TST) $(MOVES) $(PARSE) $(UTILS) $(SORT)
TEST_OBJ = $(TEST_SRC:.c=.o)

$(NAME): $(DEPENDS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

tst: $(TEST_OBJ) Makefile
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(NAME)

fs: $(DEPENDS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -fsanitize=address

%.o: %.c Makefile $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

r: $(NAME)
	./push_swap "1 3 2"

all: $(NAME) clean

clean:
	$(RM) $(OBJECTS) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
