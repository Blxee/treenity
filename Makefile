CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -pthread
NAME = treenity
INCLUDE_DIR = include
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling files.."
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(INCLUDE)
	@$(CC) -c -o $@ $< $(CFLAGS)

re: fclean all

clean:
	@printf '\033[33m%s\033[0m\n' "removing object files.."
	@rm -f $(OBJ)

fclean: clean
	@printf '\033[33m%s\033[0m\n' "removing binary.."
	@rm -f $(NAME)

.PHONY: clean
