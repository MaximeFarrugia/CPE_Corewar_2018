##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	corewar/corewar

SRC	=	$(wildcard corewar/src/*.cpp) $(wildcard corewar/src/fcts/*.cpp)

all: $(NAME) clean2

$(NAME): $(SRC)
	g++ -std=c++11 -Wwrite-strings -g3 -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-window -lsfml-system -lGLU -lGL -lglut

clean clean1 clean2:
	$(shell find . -name "*.o" -delete)
	$(shell find . -name "*~" -delete)
	$(shell find . -name "\#*\#" -delete)
	$(shell find . -name "vgcore.*" -delete)

fclean: clean1
	rm -f $(ASM)
	rm -f $(VM)

re: fclean all

.PHONY: all clean1 clean2 fclean re