##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## first Makefile
##

NAME	=	makelib

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c		\
		my_revstr.c		\
		my_strlen.c		\
		nb_len.c		\
		my_printf.c     \
		char_flag.c     \
		count_n_flag.c  \
		float_flag.c    \
		hexa_flag.c     \
		hexa_maj_flag.c \
		int_d_flag.c    \
		int_i_flag.c    \
		octal_flag.c    \
		string_flag.c   \
		unsigned_int.c  \
		my_strcpy.c		\
		my_strcpy_two.c		\
		my_strcmp.c		\
		my_getnbr.c		\
		my_strlen_n.c	\
		strdup.c		\
		my_str_to_word_array.c	\


OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc ../../libmy.a *.o
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
