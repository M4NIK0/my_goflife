##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_game_of_life
##

SRC	=	src/main.c

NAME	=	my_goflife

FLAG_LIBMY	=	-Llib/my/ -lmy

FLAG_DEBUG	=	-Wall -Wextra -g

FLAG_C_LIBS	=	-lm

COMPILATION_FLAGS	=	$(FLAG_DEBUG) $(FLAG_LIBMY) $(FLAG_C_LIBS)

all:	$(NAME)

clean:
	@make clean -C lib/my/

fclean:	clean
	rm -f $(NAME)
	@make fclean -C lib/my/

re:	fclean	all

$(NAME):
	@make -C lib/my/
	gcc -o $(NAME) $(SRC) $(COMPILATION_FLAGS)
