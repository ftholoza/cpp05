# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 07:04:09 by francesco         #+#    #+#              #
#    Updated: 2024/04/15 13:50:08 by ftholoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRC = Bureaucrat.cpp main.cpp AForm.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDES = Bureaucrat.hpp AForm.hpp
NAME = ex01

all : $(NAME)

re :fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 
clean :
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)