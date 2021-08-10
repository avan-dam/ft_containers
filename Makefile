# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-dam <avan-dam@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/23 14:38:29 by avan-dam      #+#    #+#                  #
#    Updated: 2021/08/06 15:46:50 by ambervandam   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CXX = clang++

G++ = /usr/local/bin/g++-10

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
#   -fsanitize=address -g

FILES = srcs/main.cpp

all: $(NAME)

$(NAME): $(FILES)
	$(CXX) $(FILES) $(FLAGS) -o $(NAME)

g++:
	$(G++) $(FILES) $(FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
