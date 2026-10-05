CC = cc
INCLUDE_DIR = include
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)

CFLAGS = -Wall -Werror -Wextra -pthread -I$(INCLUDE_DIR)
LDFLAGS = -pthread

SERVER_NAME = server
SERVER_SRC_DIR = src/server
SERVER_SRC = $(wildcard $(SERVER_SRC_DIR)/*.c)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_NAME = client
CLIENT_SRC_DIR = src/client
CLIENT_SRC = $(wildcard $(CLIENT_SRC_DIR)/*.c)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling server.."
	@$(CC) -o $@ $^ $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling client.."
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
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@printf '\033[33m%s\033[0m\n' "removing binaries.."
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)

.PHONY: clean
