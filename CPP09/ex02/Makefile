CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
CPPFLAGS		= 
# DEBUGFLAGS		= -fsanitize=address -g3

# *********************************** PROGRAM ******************************** #

NAME			= PmergeMe
SRCS			= main.cpp PmergeMe.cpp

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

jot3000:
	./PmergeMe `jot -r 3000 1 10000 | tr '\n' ' '`

seq3000:
	./PmergeMe `seq 1 3000 | sort -R | tr '\n' ' '`

.PHONY: all clean fclean re
