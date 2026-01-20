NAME = push_swap
TEST = sandbox.o
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include -g
RM = rm -f
MAIN = src/main.c
TEST_FILES = test/num_gen.c test/sandbox.c

PARSE = src/parse/create_stack.c	\
		src/parse/list_checks.c		\
		src/parse/arg_check.c		\

MOVES = src/moves/push.c		\
		src/moves/swap.c		\
		src/moves/rotate.c		\
		src/moves/reverse.c		\
		src/moves/print_move.c	\

SORT = src/sort/sort.c

UTILS = src/utils/ft_atoi.c		\
		src/utils/ft_split.c	\
		src/utils/ft_substr.c	\
		src/utils/ft_strlen.c	\
		src/utils/ft_strdup.c	\
		src/utils/list_clear.c	\
		src/utils/free_array.c	\

HEADERS = include/push_wap.h
SOURCES = $(MOVES) $(PARSE) $(UTILS) $(SORT)
DEPENDS = $(MAIN_OBJ) Makefile

MAIN_SRC = $(MAIN) $(SOURCES)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TEST_SRC = $(TEST_FILES) $(SOURCES)
TEST_OBJ = $(TEST_SRC:.c=.o)

$(NAME): $(DEPENDS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $(NAME)

$(TEST): $(TEST_OBJ) Makefile
	$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST)

tst: $(TEST)
	./sandbox.o

fs: $(DEPENDS)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $(NAME) -fsanitize=address

%.o: %.c Makefile $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME) clean

clean:
	$(RM) $(MAIN_OBJ) $(TEST_OBJ)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean $(NAME)
