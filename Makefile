NAME = libftprintf.a
FILENAMES = ft_printf
CFILES = $(addsuffix .c,$(FILENAMES))
OFILES = $(addsuffix .o,$(FILENAMES))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Werror -Wextra -c $(CFILES) -I ./libft/ -I ./ -o $(NAME)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OFILES)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
	make -C libft/ re
