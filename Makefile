# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-dam <avan-dam@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/23 14:38:29 by avan-dam      #+#    #+#                  #
#    Updated: 2021/08/26 14:56:18 by ambervandam   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

# TEST_NAME = test

FT_NAME = ft_containers_ft

STD_NAME = ft_containers_std

CMP_NAME = ft_containers_cmp

CXX = clang++

G++ = /usr/local/bin/g++-10

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
#  -g -fsanitize=address

FILES = srcs/main.cpp

FT_FILES = srcs/ft_main.cpp

STD_FILES = srcs/std_main.cpp

CMP_FILES = srcs/cmp_main.cpp

TEST_FILES = srcs/cmp_main.cpp srcs/std_main.cpp srcs/ft_main.cpp

all: $(NAME)

$(NAME): $(FILES)
	$(CXX) $(FILES) $(FLAGS) -o $(NAME)

run_test:$(TEST_FILES)
	$(CXX) $(FT_FILES) $(FLAGS) -o $(FT_NAME)
	./$(FT_NAME)
	$(CXX) $(STD_FILES) $(FLAGS) -o $(STD_NAME)
	./$(STD_NAME)
	$(CXX) $(CMP_FILES) $(FLAGS) -o $(CMP_NAME)
	./$(CMP_NAME)
	# $(CXX) $(TEST_FILES) $(FLAGS) -o $(TEST_NAME)

# ft:$(FT_FILES)
# 	$(CXX) $(FT_FILES) $(FLAGS) -o $(FT_NAME)

# std: $(STD_FILES)
# 	$(CXX) $(STD_FILES) $(FLAGS) -o $(STD_NAME)

# cmp: $(CMP_FILES)
# 	$(CXX) $(CMP_FILES) $(FLAGS) -o $(CMP_NAME)

clean:
	rm -f $(NAME) $(CMP_NAME) $(STD_NAME) $(STD_NAME)
	# $(STD_NAME) $(STD_NAME) $(CMP_NAME)

clean_test:
	rm -rf $(NAME) 

fclean: clean clean_test
	rm -rf myfile_ft.txt myfile_std.txt

re: fclean all
