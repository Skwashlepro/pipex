NAME = libftprintf.a
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_printf \
			print_fmt \
			prt_adr	\
			prt_char \
			prt_str	\
			prt_un	\
			prt \
			prtx 

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))


all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

${NAME}: ${OBJ_FILES}
	${AR} $@ $^
	
clean:
	rm -f ${OBJ_FILES} ${OBJ_BFILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus