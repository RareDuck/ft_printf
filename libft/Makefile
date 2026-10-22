# VARIABLES

NAME= libft.a
CC = cc
# Compilation flags
CFLAGS= -Wall -Wextra -Werror -c
# All the font code for the library
PART1= ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\

PART2= ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

PART3= ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c \
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	
FILES= $(PART1) $(PART2) $(PART3)

# Same names of font code files but with .o instead of .c
OBJ= $(FILES:%.c=%.o)

# RULES
# By default rule
all:$(NAME)
# Generating libft.h
$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
# Generating all .o files
$(OBJ):$(FILES)
	$(CC) $(CFLAGS) $(FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re all