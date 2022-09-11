# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amber <amber@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 11:12:19 by avan-bre          #+#    #+#              #
#    Updated: 2022/09/11 20:37:29 by amber            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                             UTILITIES                                        #
# **************************************************************************** #

NAMEFT		=	ft_containers
NAMESTD		=	stl_containers
SRC_DIR		=	sources/
OBJ_DIR		=	objects/
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)


SRC_FILES	=	main.cpp

# **************************************************************************** #
#                               ACTIONS                                        #
# **************************************************************************** #

CC			=	c++
RM			=	rm -rf

# **************************************************************************** #
#                               FLAGS                                          #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g
INCL		=	-Iinclude/other/ -Iinclude/containers/ -Iinclude/iterators
MEM			=	-fsanitize=address


# **************************************************************************** #
#                               RULES                                          #
# **************************************************************************** #

all:	$(NAMEFT) # $(NAMESTD)

ft:		$(NAMEFT)

#stl:	$(NAMESTD)

$(NAMEFT):	$(OBJ_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

#$(NAMESTD):	$(OBJ_DIR) $(OBJS)
#		$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
			$(RM) $(OBJS) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAMEFT)

re:			fclean all

.PHONY:		re, all, clean,