# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 12:43:22 by ale-naou          #+#    #+#              #
#    Updated: 2016/02/01 17:20:37 by ale-naou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH	= ./src/
OBJ_PATH	= ./obj/
INC_PATH	= ./include/
LIB_PATH	= ./lib

NAME		= fdf
CC			= gcc
CFLAGS		= -Wall -Werror	-Wextra
MLXFLAGS	= -L/usr/local/lib/ -I/usr/local/include \
			  -lmlx -framework OpenGL -framework AppKit

SRC_NAME	= main.c parsing.c image.c draw.c error.c
OBJ_NAME	= $(SRC_NAME.c=.o)
LIB_NAME	= libft.a

SRC			= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			= $(addprefix -I, $(INC_PATH))
LIB			= $(LIB_PATH)$(LIB_NAME)


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C lib $(OBJ)
	$(CC) $(CFLAGS) -L$(LIB_PATH) -lft $(SRC) $(INC) $(MLXFLAGS) -o $(NAME) \
	$(OBJ)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean :
	rm -rf $(OBJ_PATH)
	@make clean -C lib

fclean : clean		
	rm -fv $(NAME)
	@make fclean -C lib

re : fclean all

norme :
	norminette $(SRC)		
	norminette $(INC_PATH)*.h
	norminette $(LIB_PATH)*.[ch]

.PHONY : all clean fclean re norme lib
