NAME = BSP

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

INC = -I Fixed.hpp -I Point.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

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
