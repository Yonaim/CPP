CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
CPPFLAGS		= 
# DEBUGFLAGS		= -fsanitize=address -g3

# *********************************** PROGRAM ******************************** #

NAME			= Polymorphism
SRCS			= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

$(NAME): $(SRCS:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEBUGFLAGS) $^ -o $@

# ********************************* MAKE RULES ******************************* #

all:
	make $(NAME)

clean:
	rm -f $(SRCS:.cpp=.o)

fclean:
	rm -f $(SRCS:.cpp=.o)
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
