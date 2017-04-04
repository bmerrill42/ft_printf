NAME = libftprintf.a
FILENAMES = ft_printf
CFILES = $(addsuffix .c,$(FILENAMES))
OFILES = $(addsuffix .o,$(FILENAMES))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -L libft/ -l lft $(CFILES)
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
