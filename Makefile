NAME 		=		doom

SRCS		=		wad_reader/read_linedef.c\
					wad_reader/read_sidedef.c\
					wad_reader/read_thing.c\
					wad_reader/read_vertex.c\
					main.c\
					utils.c


SRCS_DIR 	=		src
OBJS_DIR	=		obj

OBJS		=		$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#-------------------------------------------------------------------------------
#									INCLUDES
#-------------------------------------------------------------------------------
INCLUDES_DIR = ./include/

INCLUDES =			-I $(LIBFT_DIR) -I $(INCLUDES_DIR)

#-------------------------------------------------------------------------------
#									HEADERS
#-------------------------------------------------------------------------------

HEADERS_LIST =		doom_prototypes.h\
					file.h\
					linedef.h\
					sidedef.h\
					thing.h\
					vertex.h


HEADERS =			$(addprefix $(INCLUDES_DIR), $(HEADERS_LIST))

#-------------------------------------------------------------------------------
#									LIBFT
#-------------------------------------------------------------------------------

LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_LINK = -L$(LIBFT_DIR) -lft

#-------------------------------------------------------------------------------
#									SDL_2
#-------------------------------------------------------------------------------


#-------------------------------------------------------------------------------
#									FLAGS
#-------------------------------------------------------------------------------

FLAGS_COMPILE =		-Wall -Wextra -g

FLAGS_LINK =		-lm $(LIBFT_LINK)

all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/wad_reader

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	gcc $(FLAGS_COMPILE) $(INCLUDES) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	gcc $(OBJS) $(FLAGS_LINK) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
c: clean

fclean:
	rm -rf $(OBJS_DIR)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
f: clean

re: fclean all

.PHONY: all clean fclean re c f