LIBFT =		libft.a

LIBFT_DIR =	libft

LIBFT_PATH = ${LIBFT_DIR}/

SOURCES =	main.c handle_input.c setup_list.c\
			ps_instructs.c r_instructs.c rr_instructs.c\
			bruteforce.c bf_get_next_try.c bf_basic_checks.c bf_strict_checks.c

OBJECTS =	$(SOURCES:.c=.o)

FLAGS =		-Wall -Werror -Wextra

COMPILER =	cc

NAME =		push_swap

ifndef BRUTEFORCE
	BRUTEFORCE = 12
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ${LIBFT_DIR}
	${COMPILER} ${FLAGS} ${OBJECTS} ${LIBFT_PATH}${LIBFT} -o ${NAME}

$(OBJECTS): %.o:%.c push_swap.h
	$(COMPILER) -D BRUTEFORCE=$(BRUTEFORCE) $(FLAGS) -g -c $< -o $@ -I ${LIBFT_PATH}

clean: 
	make clean -C ${LIBFT_DIR}
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${LIBFT_PATH}${LIBFT}
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
