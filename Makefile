##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile my game of life
##

SRC	=	src/main.c															\
		src/ext_usage/help_disp.c

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
