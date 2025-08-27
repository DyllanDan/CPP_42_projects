NAME = brain

CC = c++
FLAGS = -Wall -Wextra -Werror
FLAG_98 = -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all = $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(FLAG_98) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) $(FLAG_98) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
