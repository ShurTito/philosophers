NAME = philo

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIB_PROJECT = philo.a

LIB = ar rcs

SRCS =  main.c utils.c routines.c threads.c monitoring.c 

OBJS = $(SRCS:.c=.o)

$(NAME) :	$(OBJS) 
			$(LIB) $(LIB_PROJECT) $(OBJS)
			$(CC) $(CFLAGS) $(LIB_PROJECT) -o $(NAME)

$(OBJS):	%.o : %.c 
			$(CC) $(CFLAGS) -c $< -o $@


all : $(NAME)

clean:
			rm -f $(OBJS)
fclean:
			rm -f $(NAME) $(OBJS) $(LIB_PROJECT)

re : fclean all

.PHONY : all re fclean clean