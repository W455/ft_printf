# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 17:58:00 by oukrifa           #+#    #+#              #
#    Updated: 2017/10/18 00:49:38 by oukrifa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	libftprintf.a

CC				= 	gcc
LIB				= 	ar rc
RAN				= 	ranlib

CFLAGS 			= 	#-Wall -Wextra -Werror
LIB_NAME		=	libft.a

#===============================================================================
# 						PATHS
#===============================================================================
SRC_PATH		=	./srcs/

PUT_PATH		=	$(addprefix $(SRC_PATH), conversion/put/)
CVT_PATH		=	$(addprefix $(SRC_PATH), conversion/cvt/)
TOOLS_PATH		=	$(addprefix $(SRC_PATH), tools/)
FLAGS_PATH		=	$(addprefix $(SRC_PATH), flags/)
PRINT_PATH		=	$(addprefix $(SRC_PATH), print/)

INC_PATH		=	./includes/

OBJ_PATH		=	./obj/

LIB_PATH		=	./libft/

#===============================================================================
# 						SRCS
#===============================================================================
SRC_CVT		= 		cvt_mod.c \
					cvt_lc.c  \
					cvt_ls.c  \
					cvt_d.c   \
					cvt_o.c   \
					cvt_u.c   \
					cvt_x.c   \
					cvt_c.c   \
					cvt_s.c   \
					cvt_b.c   \


SRC_FLAGS	=		get_flags.c        \
					reset_flag.c        \
					#get_format_util.c \
					#color.c           \
					#get_options.c

SRC_PRINT	=		ft_printf.c \
					print_format.c

SRC_TOOLS	=		ft_itoa_base.c	\
					ft_bzero.c		\
					ft_isdigit.c	\
					ft_memchr.c		\
					ft_memset.c		\
					ft_strlen.c 	

SRC_PUT		=		cast.c     \
					put_s.c    \
					put_c.c    \
					put_ls.c   \
					put_d.c    


OBJ_NAME	=		$(SRC_FLAGS:.c=.o) \
					$(SRC_PRINT:.c=.o) \
					$(SRC_TOOLS:.c=.o)   \
					$(SRC_CVT:.c=.o)   \
					$(SRC_PUT:.c=.o)

SRC			=		$(addprefix $(PRINT_PATH), $(SRC_PRINT)) \
					$(addprefix $(FLAGS_PATH), $(SRC_FLAGS)) \
					$(addprefix $(TOOLS_PATH), $(SRC_TOOLS)) \
					$(addprefix $(CVT_PATH), $(SRC_CVT))     \
					$(addprefix $(PUT_PATH), $(SRC_PUT))	 \

OBJ			=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC			=		$(INC_PATH)

#===============================================================================
# 						Rules
#===============================================================================
all 		: 		$(NAME)

$(NAME) 	:		$(SRC)
					@echo "Compiling sources..."
					mkdir -p $(OBJ_PATH)
					make -C libft
					make -C libft clean
					$(CC) $(CFLAGS) -c $^ -I $(INC)
					mv $(OBJ_NAME) $(OBJ_PATH)
					#@clear
					@echo "\033[0;32mDone\033[0m\n"

					@echo "Building libftprintf.a..."
					$(LIB) $(NAME) $(OBJ)
					#@clear
					@echo "\033[0;32mDone\033[0m\n"

					@echo "Ranlibing libftprintf.a..."
					$(RAN) $(NAME)
					#@clear
					@echo "\033[0;32mDone\033[0m\n"
					@echo "\033[3;94m!libftprintf.a done!\033[0m"
					

clean 		:
					@echo "Deleting .os... for libftprintf.a"
					make -C libft clean
					@rm -rf $(OBJ_PATH)
					@echo "\033[0;32mDone\033[0m\n"

fclean 		: 		clean
					@echo "Deleting libftprintf.a..."
					make -C libft fclean	
					@rm -f $(NAME)
					@echo "\033[0;32mDone\033[0m\n"

re 			: 		fclean $(NAME)

mr_propre	: 		re clean

test		:		$(NAME)
					$(CC) $(CFLAGS) main.c -o test -L./ -lftprintf -Llibft -lft -I $(INC)

test1		:		$(NAME)
					make -C 2 re
					$(CC) $(CFLAGS) main.c -o test1 -L./2/ -lftprintf -Llibft -lft -I $(INC)

.PHONY: 			re fclean clean all mr_propre print
