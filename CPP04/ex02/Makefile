# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 10:44:02 by fli               #+#    #+#              #
#    Updated: 2024/11/09 16:57:33 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

C_FILE = main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

INCLUDES = .

NAME = polymorphism

OBJ = ${C_FILE:.cpp=.o}

%.o: %.cpp
	${CC} ${CXXFLAGS} -I ${INCLUDES} -c $< -o ${<:.cpp=.o}

${NAME}: $(OBJ)
	${CC} ${CXXFLAGS} ${OBJ} -I ${INCLUDES} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
