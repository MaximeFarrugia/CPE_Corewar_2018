##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

ASM	=	asm/asm

VM	=	corewar/corewar

SRC1	=	$(wildcard asm/src/*.c)

SRC2	=	$(wildcard corewar/src/*.c) $(wildcard corewar/src/fcts/*.c) $(wildcard corewar/src/cwncurses/*.c)

CFLAGS	=	-g3 -W -Wall -Wextra

all: $(ASM) $(VM) clean2

asm $(ASM): $(SRC1)
	make -C ./lib/my
	gcc $(CFLAGS) -o $(ASM) $(SRC1) -L./lib -lmy

vm $(VM): $(SRC2)
	make -C ./lib/my
	gcc $(CFLAGS) -o $(VM) $(SRC2) -L./lib -lmy -lncurses

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