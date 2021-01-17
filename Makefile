##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR		=		src

INCDIR		=		include

SRC     	=		$(SRCDIR)/Circuit/Pin.cpp \
					$(SRCDIR)/Circuit/Gates.cpp \
					$(SRCDIR)/Circuit/Circuit.cpp \
					$(SRCDIR)/Components/Xor.cpp \
					$(SRCDIR)/Components/Nand.cpp \
					$(SRCDIR)/Components/Nor.cpp \
					$(SRCDIR)/Components/Or.cpp \
					$(SRCDIR)/Components/And.cpp \
					$(SRCDIR)/Components/Factory.cpp \
					$(SRCDIR)/Components/Chipset.cpp \
					$(SRCDIR)/Components/Input.cpp \
					$(SRCDIR)/Shell/Shell.cpp \
					$(SRCDIR)/Parser/Parser.cpp \
					$(SRCDIR)/Components/Output.cpp \
					$(SRCDIR)/Components/4081.cpp \
					$(SRCDIR)/Components/4011.cpp \
					$(SRCDIR)/Components/4001.cpp \
					$(SRCDIR)/Components/4071.cpp \
					$(SRCDIR)/Components/4030.cpp \
					$(SRCDIR)/Components/True.cpp \
					$(SRCDIR)/Components/False.cpp \
					$(SRCDIR)/Components/Clock.cpp \
					$(SRCDIR)/Parser/Utils/utils.cpp \
					$(SRCDIR)/main.cpp \

OBJ			=		$(SRC:.cpp=.o)

CC			=		g++

NAME		=		nanotekspice

CPPFLAGS	+=    	-I include/ -g3

all:				$(NAME)

$(NAME):			$(OBJ)
					$(CC) $(OBJ) -o $(NAME)

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re

