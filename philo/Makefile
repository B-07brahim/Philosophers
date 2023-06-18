SRC = main.c ft_info.c ft_check_arg.c ft_init.c philosophers.c if_one_philo.c staff.c \
update_time.c print_msg.c ft_calloc.c ft_atoi.c ft_free.c my_usleep.c ms_time.c creat_philo.c\
died.c
NAME = philo
HEADER = philosophers.h
OBJ = $(SRC:.c=.o)
CC  = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f
%.o:%.c $(HEADER)
			@$(CC)  $(CFLAGS) -c $<	-o $@
			@ echo "\033[1;32m         ->Compiled  $<  " 
			@ echo 
$(NAME): $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@ echo
			@ echo
			@ echo "\033[1;33m         ->Compiled Successfully--- ツ"
all: $(NAME)

clean:
		@$(RM) $(OBJ)
		@ echo "\033[1;31m         ---------- Cleaned-------  ツ"
fclean: clean
		@$(RM) $(NAME)
re: fclean all

.PHONY = all re fclean clean