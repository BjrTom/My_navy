##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## first Makefile
##

SRC	=	main.c	\
		other.c	\
		other_two.c	\
		temp.c	\
		all_tab.c	\
		binaire.c	\
		usefull.c	\

NAME	=	my_navy

LIBPATH	=	lib/my/

COMP	=	gcc -o $(NAME) $(SRC) -g3

LIBCOMP	=	-L ./ -lmy

all:	$(NAME)

$(NAME):
	make re -C $(LIBPATH)
	$(COMP) $(LIBCOMP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
