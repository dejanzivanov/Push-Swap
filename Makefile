# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 04:53:26 by dzivanov          #+#    #+#              #
#    Updated: 2021/12/03 04:53:29 by dzivanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_OBJSD = objs

LIBFT_SRCD = srcs

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = inc/

SRCD		=	./srcs/

SRC 		=	push_swap.c ft_error_handler1.c ft_error_handler2.c ft_argument_check.c \
				ft_sorting_handlers1.c ft_sorting_utilities1.c ft_helpers.c ft_sorting_utilities2.c \
				ft_sorting_utilities3.c ft_sorting_handlers2.c ft_helpers2.c
SRCS_FILES	= $(addprefix $(SRCD),$(SRC))
OBJD		= ./obj/

SRCS_OBJS 		= $(SRCS_FILES:$(SRCD)%.c=$(OBJD)%.o)
BUILD 		= $(SRCS_OBJS:$(OBJD)%.o)

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror
#CFLAGS         =

RM         = rm -f

AR         = ar rcs

LIBFT_OBJS    = ${LIBFT_PATH}${LIBFT_OBJSD}/*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -I ${HEADD} -lbsd -c -o $@ $<


all:				${NAME}

${NAME}:    ${SRCS_OBJS} make
			${CC}${FLAGS} ${SRCS_FILES} ${LIBFT_OBJS} -o ${NAME}

make:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re