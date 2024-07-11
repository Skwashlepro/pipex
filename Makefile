NAME 		= pipex
LIB		= includes/libft/libft.a
PTF		= includes/printf/libftprintf.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc
AR			= ar rcs
VPATH = srcs
LIBFT_PATH 	= ./includes/libft
PRINTF_PATH = ./includes/printf
INC = -Iincludes/

SRC_FILES	= main pipex

OBJ	= $(addsuffix .o, $(SRC_FILES))

all: $(LIB) $(PTF) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I/usr/include -O2 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC) $(LIB) $(PTF) $(NAME)

$(LIB): 
	@make -s -C $(LIBFT_PATH)

$(PTF): 
	@make -s -C $(PRINTF_PATH)

clean:
	@make -s $@ -C $(LIBFT_PATH)
	@make -s $@ -C $(PRINTF_PATH)
	rm -f ${OBJ} 

fclean: clean
	@make -s $@ -C $(LIBFT_PATH)
	@make -s $@ -C $(PRINTF_PATH)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re