# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fli <fli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 10:44:02 by fli               #+#    #+#              #
#    Updated: 2024/11/09 16:24:20 by fli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

C_FILE = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

INCLUDES = .

NAME = interface

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
