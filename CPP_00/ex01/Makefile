NAME = phonebook

CC = c++
FLAGS = -Wall -Wextra -Werror
FLAG_98 = -std=c++98

SRC = Contact.cpp \
PhoneBook.cpp \
str_is_alpha.cpp \
str_is_numeric.cpp \
ft_strlen.cpp \
main.cpp

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
