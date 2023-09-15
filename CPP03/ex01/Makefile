CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
CPPFLAGS		= 

# *********************************** PROGRAM ******************************** #

NAME			= scav
SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp

$(NAME): $(SRCS:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@

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