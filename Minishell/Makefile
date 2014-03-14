NAME		=	minishell

SRCS		=	main.c			\
			epure.c			\
			list_env.c		\
			error.c			\
			free.c			\
			init_env.c		\
			do_new_line.c		\
			cmd_env.c		\
			read_line.c		\
			replace_home.c		\
			my_memset.c		\
			do_cmd.c		\
			check_particular.c	\
			parser.c		\
			my_getenv.c		\
			do_exit.c		\
			do_cd.c			\
			do_pwd.c		\
			do_env.c		\
			do_binaries.c		\
			make_table.c		\
			aff_tab.c

OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-W -ansi -pedantic
RM		=	rm -f
CC		=	gcc


all		:$(NAME)

$(NAME)		:$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean		:
		$(RM) $(OBJS)

fclean		:clean
		$(RM) $(NAME)

re		:fclean all
