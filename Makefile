CC = clang
CLAGS = -Wall -Wextra -Werror -Wpedantic -lncurses

NAME = endgame

SRCD = src
INCD = inc
RESD = resource

SRCC = $(addprefix $(SRCD)/, *.c)

all: install

install:
	@$(CC) $(CFLAGS) $(SRCC) -I $(INCD) -o $(NAME)

uninstall:
	rm -rf $(NAME)
