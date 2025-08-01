NAME = program

SRC =	ClapTrap.cpp	\
		ScavTrap.cpp	\
		main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJ): %.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re