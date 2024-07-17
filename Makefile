NAME 		= pipex
LIB			= includes/libft/libft.a
CFLAGS		= -Wall -Werror -Wextra -g3
CC			= cc
VPATH		= srcs
LIBFT_PATH 	= ./includes/libft
INC = -Iincludes/

SRC_FILES	= main pipex utils

OBJ	= $(addsuffix .o, $(SRC_FILES))

all: $(LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I/usr/include -O2 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(LIB): 
	@make -s -C $(LIBFT_PATH)

clean:
	@make -s $@ -C $(LIBFT_PATH)
	rm -f ${OBJ} 

fclean: clean
	@make -s $@ -C $(LIBFT_PATH)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re