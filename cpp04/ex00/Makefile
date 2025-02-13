NAME = Polymorphism

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

INC = -I Animal.hpp -I Dog.hpp -I Cat.hpp -I WrongAnimal.hpp -I WrongCat.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wshadow -Wno-shadow -Wall -Wextra -Werror -std=c++98 -pedantic

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
