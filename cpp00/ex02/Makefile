NAME = The\ Job\ Of\ Your\ Dreams

SRC = tests.cpp Account.cpp

INC = -I Account.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 #-pedantic

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
