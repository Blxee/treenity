CC = cc
INCLUDE_DIR = include
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)

CFLAGS = -Wall -Werror -Wextra -pthread -I$(INCLUDE_DIR)
LDFLAGS = -pthread

NAME = treenity
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling files.."
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(INCLUDE)
	@$(CC) -c -o $@ $< $(CFLAGS)

norm:
	@printf '\033[34m%s\033[0m\n' "checking with norminette.."
	@norminette .
	@printf '\033[34m%s\033[0m\n' "all good"

re: fclean all

clean:
	@printf '\033[33m%s\033[0m\n' "removing object files.."
	@rm -f $(OBJ)

fclean: clean
	@printf '\033[33m%s\033[0m\n' "removing binary.."
	@rm -f $(NAME)

.PHONY: clean
