NAME = libftprintf.a

SRCS = ft_printf.c ft_string.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ft_printf.h 
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

%.o:	%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS) 

fclean	:	clean
			$(RM) $(NAME)

re	:	fclean $(NAME)

.PHONY:	all clean fclean re
