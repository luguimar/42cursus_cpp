NAME = Interface\ \&\ recap

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

INC = -I AMateria.hpp -I Ice.hpp -I Cure.hpp -I Character.hpp -I MateriaSource.hpp -I IMateriaSource.hpp -I ICharacter.hpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wshadow -Wno-shadow -Wall -Wextra -Werror -std=c++98 #-pedantic

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
