# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-dam <avan-dam@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/23 14:38:29 by avan-dam      #+#    #+#                  #
#    Updated: 2021/09/10 12:36:23 by ambervandam   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

FT_NAME = srcs/tests/ft_containers_ft

STD_NAME = srcs/tests/ft_containers_std

CMP_NAME = srcs/tests/ft_containers_cmp

CXX = clang++

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

FT_FILES = srcs/tests/ft_main.cpp

STD_FILES = srcs/tests/std_main.cpp

CMP_FILES = srcs/tests/main.cpp

all: $(NAME)

$(NAME): $(CMP_FILES) $(STD_FILES) $(FT_FILES)
	$(CXX) $(FT_FILES) $(FLAGS) -o $(FT_NAME)
	./$(FT_NAME)
	$(CXX) $(STD_FILES) $(FLAGS) -o $(STD_NAME)
	./$(STD_NAME)
	$(CXX) $(CMP_FILES) $(FLAGS) -o $(CMP_NAME)
	./$(CMP_NAME)

clean:
	rm -f $(NAME) $(CMP_NAME) $(STD_NAME) $(FT_NAME)

fclean: clean 
	rm -rf srcs/tests/myfile_ft.txt srcs/tests/myfile_std.txt srcs/tests/myfile_ft_time.txt srcs/tests/myfile_std_time.txt

re: fclean all
