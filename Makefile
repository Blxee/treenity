CC = cc
INCLUDE_DIR = include
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)

CFLAGS = -Wall -Werror -Wextra -pthread -I$(INCLUDE_DIR)
LDFLAGS = -pthread

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRC_DIR = src/server
CLIENT_SRC_DIR = src/client
COMMON_SRC_DIR = src/common
OBJ_DIR = obj

SERVER_SRC = $(wildcard $(SERVER_SRC_DIR)/*.c)
CLIENT_SRC = $(wildcard $(CLIENT_SRC_DIR)/*.c)
COMMON_SRC = $(wildcard $(COMMON_SRC_DIR)/*.c)

SERVER_OBJ = $(SERVER_SRC:src/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:src/%.c=$(OBJ_DIR)/%.o)
COMMON_OBJ = $(COMMON_SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) $(COMMON_OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling server.."
	@$(CC) -o $@ $^ $(LDFLAGS)

$(CLIENT_NAME): $(CLIENT_OBJ) $(COMMON_OBJ)
	@printf '\033[32m%s\033[0m\n' "compiling client.."
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< $(CFLAGS)

norm:
	@printf '\033[34m%s\033[0m\n' "checking with norminette.."
	@norminette .
	@printf '\033[34m%s\033[0m\n' "all good"

re: fclean all

clean:
	@printf '\033[33m%s\033[0m\n' "removing object files.."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf '\033[33m%s\033[0m\n' "removing binaries.."
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)

.PHONY: all norm re clean fclean
