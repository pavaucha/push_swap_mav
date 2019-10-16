
NAME = checker

CC = cc

CFLAGS			:=	-Wall  \
					-Werror \
					-Wextra \
					-g -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=address

SOURCES = 	srcs/checker/srcs/main.c
		 

INCLUDES =	srcs/checker/includes/checker.h 

SRCS 			=	$(SOURCES)

OFILES			=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): libft $(OFILES)
	@gcc $(OFILES) $(CFLAGS) $(LIBS) libft/libft.a -o $(NAME)

%.o: %.c $(INCLUDES)
	@$(CC)  $< -c $(CFLAGS) -Iincludes -Ilibft/includes -o $@

libft: libft/libft.a

libft/libft.a:
	@make -C libft/

clean:
	@/bin/rm -f $(OFILES)
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
