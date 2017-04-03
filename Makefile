NAME = ft_printf.a
FILENAMES = ft_printf
CFILES = $(addsuffix .c,$(FILENAMES))
OFILES = $(addsuffix .o,$(FILENAMES))

all: $(NAME)

$(NAME):
	gcc -c $(CFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
