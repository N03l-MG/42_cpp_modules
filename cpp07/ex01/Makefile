NAME = ex01

CMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++17 -Iinclude

SRC = main.cpp
OBJ_DIR = _obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: info $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@$(CMP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CMP) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "Succesfully compiled $(NAME).\n"

info:
	@printf "Compiling $(NAME)...\n"

clean:
	@printf "Cleaned object files.\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "Cleaned executable.\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re