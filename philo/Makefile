NAME = philo

INC 	= philo.h

SRC		=	main.c\
			controler.c\
			init.c\
			time.c\
			action_controller.c\
			philo_do.c\
			take_fork.c\
			destroy_thread.c\

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror -pthread -g

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