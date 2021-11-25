NAME = push_swap

SRCS = pushswap.c ps_moves.c errors.c ps_utils.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${SRCS}
		@${CC} ${CFLAGS} ${SRCS} -o ${NAME} 

all:	${NAME}

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all