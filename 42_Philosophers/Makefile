NAME = philo

INC 	= philo.h

SRC		=	main.c\
			arg_control.c\
			init.c\
			time.c\
			messager.c\
			philo_do.c\
			destroy.c\
			routine.c\

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) 

all: $(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
		$(CC) $(FLAGS) -c $< -o  $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
