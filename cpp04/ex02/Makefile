NAME = ex02

SRC =	AAnimal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		WrongAnimal.cpp	\
		WrongDog.cpp	\
		WrongCat.cpp	\
		Brain.cpp	\
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
