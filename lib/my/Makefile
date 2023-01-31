##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for libmy
##

SRC	=	src/my_printf/my_getnbr.c											\
		src/my_printf/my_nbrs_pos_neg.c										\
		src/my_printf/my_printf.c											\
		src/my_printf/my_strcmp.c											\
		src/my_printf/my_strcpy.c											\
		src/my_printf/my_strlen.c											\
		src/my_printf/my_strcmp.c											\
		src/my_printf/my_strlowcase.c										\
		src/my_printf/print_flags_id.c										\
		src/my_printf/print_get_flags.c										\
		src/my_printf/print_struct.c										\
		src/my_putnbr_str.c													\
		src/my_printf/print_conversions/print_conversion_chars.c			\
		src/my_printf/print_conversions/print_conversion_double.c			\
		src/my_printf/print_conversions/print_conversion_int.c				\
		src/my_printf/print_conversions/print_ptr_conversion.c				\
		src/my_printf/print_conversions/print_conversion_int_bonus.c		\
		src/my_printf/print_conversions/print_conversion_int_len_modif.c	\
		src/my_printf/print_conversions/useful/math.c						\
		src/my_printf/print_conversions/useful/unsigned_math.c				\
		src/my_printf/print_conversions/useful/my_putfnbr.c					\
		src/my_printf/print_conversions/print_conversion_g_use.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean	all

maintest:	all	clean
	gcc main.c -L ./ -lmy -Wall -Wextra -g
	./a.out

maincleantest:	fclean
	rm -f a.out

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
