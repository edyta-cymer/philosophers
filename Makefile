NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = main.c \
       init.c \
	   utills.c \
	   validate_input.c \
	   
OBJS = $(SRCS:.c=.o)

# Kolory dla estetyki
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Removed $(NAME).$(RESET)"

re: fclean all
