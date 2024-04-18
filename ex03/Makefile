# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francesco <francesco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 07:04:09 by francesco         #+#    #+#              #
#    Updated: 2024/04/18 08:42:55 by francesco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDES = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp
NAME = ex03

all : $(NAME)

re :fclean $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 
clean :
	rm -f $(OBJ)
fclean: clean
	rm -rf $(NAME)