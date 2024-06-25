NAME = push_swap #Nombre ejecutable

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g #fsanitize=address for leak control

SRCS = check_args.c errors.c main.c create_list.c push.c reverse_rotate.c rotate.c swap.c
OBJS = $(SRCS:.c=.o) #When OBJS is executed, it changes .c to .o

INC = -I inc -I libft #Searches libraries in both folders
LIBRARY = -L libft #Searches makefiles in libft folder

%.o: %.c #Cannot create .o if the .c does not exist (for creating the objects), also the program knows how to create them now (line below)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME) = $(OBJS) maker #it makes objects and libft executable, also compile all objects with libraries, etc and creates executable NAME
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo "$(NAME) created"

maker:
	@make -C libft

clean:
	@$(RM) $(OBJS)
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

run: all clean

.PHONY: all clean fclean re run maker