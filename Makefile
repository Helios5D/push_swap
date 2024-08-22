NAME = push_swap
NAME_BONUS = checker

LIBFT = ./libft/libft.a

CC = cc

SRC = 	src/main.c src/parsing.c \
		src/stack_1.c src/stack_2.c \
		src/push.c src/swap.c \
		src/sort_1.c src/sort_2.c src/sort_3.c\
		src/rotate.c src/rotate_rev.c

SRC_BONUS =	src_bonus/main_bonus.c src_bonus/read_bonus.c \
			src_bonus/stack_1_bonus.c src_bonus/stack_2_bonus.c \
			src_bonus/push_bonus.c src_bonus/rotate_bonus.c \
			src_bonus/rotate_rev_bonus.c src_bonus/swap_bonus.c \
			src_bonus/instructions_bonus.c src_bonus/parsing_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = includes/

CFLAGS := -Wall -Wextra -Werror -g3

BLUE = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m

all: $(LIBFT) $(NAME)

bonus : $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@make --no-print-directory -C ./libft

$(NAME): $(OBJ)
	@echo -e '$(BLUE)Linking executable$(NC)'
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -I$(INCLUDES)
	@echo -e '$(GREEN)Executable ./$(NAME) linked successfully$(NC)'

$(NAME_BONUS): $(OBJ_BONUS)
	@echo -e '$(BLUE)Linking executable$(NC)'
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS) -I$(INCLUDES)
	@echo -e '$(GREEN)Executable ./$(NAME_BONUS) linked successfully$(NC)'


%.o: %.c
	@echo -e '$(BLUE)Compiling $<$(NC)'
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)
	@echo -e '$(GREEN)Compiled $< successfully$(NC)'

clean:
	@make fclean --no-print-directory -C ./libft
	@echo -e '$(BLUE)Cleaning up object files$(NC)'
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo -e '$(GREEN)Object files cleaned up successfully$(NC)'

fclean: clean
	@echo -e '$(BLUE)Cleaning up executable$(NC)'
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo -e '$(GREEN)Executable cleaned up successfully$(NC)'

re: fclean all

.PHONY: all bonus clean fclean re
