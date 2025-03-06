NAME = ex00

CMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++11 -Iinclude

SRC = main.cpp \
	  src/Animal.cpp src/Dog.cpp src/Cat.cpp \
	  src/WrongAnimal.cpp src/WrongCat.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src

$(OBJ_DIR)/%.o: %.cpp
	$(CMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CMP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re