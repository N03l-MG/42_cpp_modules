NAME = phonebook

CMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp contact.cpp phonebook.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CMP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re