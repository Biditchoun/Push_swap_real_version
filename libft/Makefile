SOURCES = str_len.c mem_set.c mem_cpy.c mem_move.c str_cpy.c strl_cpy.c\
		str_chr.c strn_cmp.c strn_str.c str_dup.c split.c\
		int_chr.c check_if_int.c arr_dup.c print_arr.c\
		a_toi.c a_tol.c i_toa.c min.c max.c putnbr_base.c putunbr_base.c\
		ft_printf.c printf_conversions1.c printf_conversions2.c\
		rtint_free.c rtptr_free.c rtint_ffree.c rtptr_ffree.c write_rtint.c write_rtptr.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

COMPILER = cc

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): %.o:%.c libft.h
	$(COMPILER) $(FLAGS) -c $< -o $@ -I includes

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
