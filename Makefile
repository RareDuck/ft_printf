# VARIABLES

NAME= libftprintf.a
LIBFT_DIR= libft
LIBFT= $(LIBFT_DIR)/libft.a
CC = cc
# Compilation flags
CFLAGS= -Wall -Wextra -Werror -c
# All the font code for the library
SOURCES= ft_printf.c\
		flag_manager.c\
		format_0.c\
		format_1.c\
		utils.c


	
FILES= $(SOURCES)

# Same names of font code files but with .o instead of .c
OBJ= $(FILES:%.c=%.o)

# RULES
# By default rule
all: $(NAME)
# Generating libft.h
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)/*.o

# If it needs any .o files, it will use the corresponding .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean 
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: clean fclean re all