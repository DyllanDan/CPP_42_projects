NAME = claptrap

CC = c++
FLAGS = -Wall -Wextra -Werror -I.
FLAG_98 = -std=c++98

SRC = main.cpp \
ClapTrap.cpp ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(FLAG_98) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) $(FLAG_98) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re