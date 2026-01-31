# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:09:35 by matnusko          #+#    #+#              #
#    Updated: 2025/10/12 13:01:35 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Wextra -Werror

PART1 = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c \
		src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c \
		src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c \
		src/ft_memset.c src/ft_strchr.c src/ft_strdup.c src/ft_strlcat.c \
		src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c src/ft_strnstr.c \
		src/ft_strrchr.c src/ft_tolower.c src/ft_toupper.c

PART2 = src/ft_substr.c src/ft_strjoin.c src/ft_strtrim.c \
		src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c \
		src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c

PRINTF = src/ft_printf.c src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c \
		src/ft_putunsigned.c src/ft_puthex.c src/ft_putpointer.c \
		src/ft_putunbr.c
		
GNL = src/get_next_line.c src/get_next_line_utils.c


BONUS = src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c \
		src/ft_lstlast.c src/ft_lstadd_back.c src/ft_lstdelone.c \
		src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c

SRCS = ${PART1} ${PART2} ${PRINTF} ${BONUS} ${GNL}

NAMELIB = my_lib.a

OBJ = ${SRCS:.c=.o}

INCLUDE = include/libft.h




.c.o:
			${CC} ${FLAG} -c $< -o $@
			
all:		${NAMELIB}

${NAMELIB}:		${OBJ}
	ar rcs ${NAMELIB} ${OBJ}
	
clean:
	rm -f ${OBJ}
	
fclean: clean
	rm -f ${NAMELIB}
	
re:	fclean all
	
.PHONY:		all clear fclean re  