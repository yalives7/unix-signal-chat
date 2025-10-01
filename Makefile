CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = 	src/client.c\
		src/server.c\
		src/utils.c\

SRC_BONUS = src/client_bonus.c\
			src/server_bonus.c\
			src/utils.c\

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME_CLIENT = client
NAME_SERVER = server

NAME = $(NAME_SERVER) $(NAME_CLIENT)

all: $(NAME)

$(NAME_SERVER): src/server.o src/utils.o
		$(CC) src/server.o src/utils.o -o $(NAME_SERVER)

$(NAME_CLIENT): src/client.o src/utils.o
		$(CC) src/client.o src/utils.o -o $(NAME_CLIENT)
	
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	
$(NAME_SERVER_BONUS): src/server_bonus.o src/utils.o
		$(CC) src/server_bonus.o src/utils.o -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): src/client_bonus.o src/utils.o
		$(CC) src/client_bonus.o src/utils.o -o $(NAME_CLIENT_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus