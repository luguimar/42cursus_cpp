NAME = phonebook

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 -pedantic

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
