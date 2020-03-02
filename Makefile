# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edessain <edessain@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 09:24:00 by edessain          #+#    #+#              #
#    Updated: 2020/02/12 16:04:29 by edessain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_LIST = \
			ft_printf.c \
			aux_check_conversion.c \
			aux_check_flag.c \
			print_c.c \
			print_s.c \
			print_i.c \
			print_i_bis.c \
			print_u.c \
			print_u_bis.c \
			print_p.c \
			print_x.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}
HEADER			= include
FOLDER			= srcs
LIBFT 			= libft
CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}
$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rcs $(NAME) $(OBJS)
bonus:			${NAME}
%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)
fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
re:				fclean all

.PHONY: 		all fclean clean re
