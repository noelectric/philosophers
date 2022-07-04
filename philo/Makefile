CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRC = ./philo.c\
	  ./shared/free_all.c\
	  ./shared/ft_atoi.c\
	  ./shared/lst_fun.c\
	  ./shared/philo_utils_0.c\
	  ./shared/philo_utils_1.c\
	  ./shared/routine.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

OBJ_DIR = ./obj

INC = include/philo.h

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.c  $(INC)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		@rm -rf $(OBJ_DIR)

fclean : clean
		@rm -rf $(NAME)

re : fclean $(NAME)
