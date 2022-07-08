# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 11:12:19 by avan-bre          #+#    #+#              #
#    Updated: 2022/07/08 18:15:22 by avan-bre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                             UTILITIES                                        #
# **************************************************************************** #

NAME		=	containers
SRC_DIR		=	sources/
OBJ_DIR		=	objects/
SUB_DIR		=	$(addprefix objects/, vector)
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)


SRC_FILES	=	main.cpp # $(NAMESPACE) $(VECTOR)
#NAMESPACE	=	$(addprefix namespace/, ft.cpp)
VECTOR		=	$(addprefix vector/, vector.cpp)

# **************************************************************************** #
#                               ACTIONS                                        #
# **************************************************************************** #

CC			=	c++
RM			=	rm -rf

# **************************************************************************** #
#                               FLAGS                                          #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror #-std=c++98
INCL		=	-Iinclude/
MEM			=	-fsanitize=address


# **************************************************************************** #
#                               RULES                                          #
# **************************************************************************** #

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
		mkdir $(OBJ_DIR) $(SUB_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
			$(RM) $(OBJS) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		re, all, clean,