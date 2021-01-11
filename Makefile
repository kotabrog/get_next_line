CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAINFILE	= main.c
CLIBS		= -L . -lft
RM			= rm -f
AR			= ar r
OBJS		= $(SRCS:%.c=%.o)
LIBNAME		= libft.h
NAME		= libft.a
TARGET		= main.exe
SRCS		= get_next_line.c get_next_line_utils.c

all:	$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -c $(SRCS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) *.o

fclean:	clean
			$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re