NAME = ex03

CMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC = main.cpp src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp src/DiamondTrap.cpp
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