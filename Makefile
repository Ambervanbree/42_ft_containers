# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amber <amber@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 11:12:19 by avan-bre          #+#    #+#              #
#    Updated: 2022/09/16 09:43:23 by amber            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                             UTILITIES                                        #
# **************************************************************************** #

NAME			=	ft_containers
NAME_STD		=	std_containers
OBJS_FT			=	$(SRCS_FT:.cpp=.o)
OBJS_STD		=	$(SRCS_STD:.cpp=.o)
SRCS_FT			=	sources/main_ft.cpp
SRCS_STD		=	sources/main_std.cpp

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

all:			$(NAME) $(NAME_STD)

ft:				$(NAME)

std:			$(NAME_STD)

$(NAME):		$(OBJS_FT)
		$(CC) $(OBJS_FT) -o $@

$(NAME_STD):	$(OBJS_STD)
		$(CC) $(OBJS_STD) -o $@

$(OBJS_FT):
		$(CC) -c $(SRCS_FT) $(CFLAGS) -o $@ $(INCL)

$(OBJS_STD):
		$(CC) -c $(SRCS_STD) $(CFLAGS) -o $@ $(INCL)

clean:
			$(RM) $(OBJS_FT) $(OBJS_STD) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME) $(NAME_STD)

re:			fclean all

.PHONY:		re, all, clean, fclean, std, ft