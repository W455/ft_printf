# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 17:58:00 by oukrifa           #+#    #+#              #
#    Updated: 2017/09/07 21:27:40 by oukrifa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC	= gcc
LIB	= ar rc
RAN	= ranlib

CFLAGS = -Wall -Wextra -Werror

#===============================================================================
# 						PATHS
#===============================================================================
SRC_PATH		=	./srcs/

CVT_PATH		=	$(addprefix $(SRC_PATH), cvt/)
PRIMARY_PATH	=	$(addprefix $(SRC_PATH), primary/)
PRINT_PATH		=	$(addprefix $(SRC_PATH), print/)
PUT_PATH		=	$(addprefix $(SRC_PATH), put/)
UTIL_PATH		=	$(addprefix $(SRC_PATH), util/)

INC_PATH		=	./includes/

OBJ_PATH		=	./obj/

#===============================================================================
# 						SRCS
#===============================================================================
SRC_CVT		= 	cvt_d.c \
				cvt_o.c \
				cvt_u.c \
				cvt_x.c \
				cvt_p.c \
				cvt_c.c \
				cvt_lc.c \
				cvt_s.c \
				cvt_ls.c \
				cvt_b.c \
				cvt_percent.c \
				cvt_inv.c \
				cvt_f.c \
				cvt_n.c \
				uni.c \
				uni_util.c

SRC_PRIMARY	=	get_format.c \
				get_format_util.c \
				color.c \
				get_options.c

SRC_PRINT	=	ft_printf.c \
				ft_sprintf.c

SRC_PUT		=	ft_putd.c \
				ft_puts.c \
				ft_puto.c \
				ft_putx.c \
				ft_putls.c \
				ft_putp.c \
				ft_putu.c \
				ft_putf.c \
				ft_putls_util.c \
				ft_put_util.c

SRC_UTIL	=	ft_isdigit.c \
				ft_iterative_power_long_double.c \
				ft_strlen.c \
				ft_memset.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strchr.c

OBJ_NAME	=	$(SRC_CVT:.c=.o) \
				$(SRC_PRIMARY:.c=.o) \
				$(SRC_PRINT:.c=.o) \
				$(SRC_PUT:.c=.o) \
				$(SRC_UTIL:.c=.o)


SRC			=	$(addprefix $(CVT_PATH), $(SRC_CVT)) \
				$(addprefix $(PRIMARY_PATH), $(SRC_PRIMARY)) \
				$(addprefix $(PRINT_PATH), $(SRC_PRINT)) \
				$(addprefix $(PUT_PATH), $(SRC_PUT)) \
				$(addprefix $(UTIL_PATH), $(SRC_UTIL))

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			=	$(addprefix -I, $(INC_PATH))

#===============================================================================
# 						Rules
#===============================================================================
all : $(NAME)

print : 
	gcc $(SRC) -I $(INC_PATH) maintest.c -o yo
#-fsanitize=address

meuh :
	gcc $(SRC) -I $(INC_PATH) wchar_brute.c -o meu
#-fsanitize=address

$(NAME) :
	@echo "Compiling .os..."
	mkdir -p $(OBJ_PATH)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) -c -I includes/
	clear
	@echo "\033[0;32mDone\033[0m\n"

	@echo "Building libftprintf.a..."
	$(LIB) $(NAME) $(OBJ)
	clear
	@echo "\033[0;32mDone\033[0m\n"

	@echo "Ranlibing libftprintf.a..."
	$(RAN) $(NAME)
	clear
	@echo "\033[0;32mDone\033[0m\n"

	@echo "\033[3;94m!libftprintf.a done!\033[0m"

clean :
	@echo "Deleting .os... for libftprintf.a"
	make -C libft clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;32mDone\033[0m\n"

fclean : clean
	@echo "Deleting libftprintf.a..."
	make -C libft fclean	
	@rm -f $(NAME)
	@echo "\033[0;32mDone\033[0m\n"

re : fclean $(NAME)

.PHONY: re fclean clean all mr_propre print meuh
