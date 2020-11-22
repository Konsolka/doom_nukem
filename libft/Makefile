NAME =				libft.a

NAME_DEBUG =		libftdebug.a

#-------------------------------------------------------------------------------
#								SOURCE FILES
#-------------------------------------------------------------------------------

SRCS =				bits_array/bits_arr_size.c				\
					bits_array/bits_arr_create.c			\
					bits_array/bits_arr_destroy.c			\
					bits_array/bits_arr_valueof.c			\
					bits_array/bits_arr_fill_true.c			\
					bits_array/bits_arr_to_string.c			\
					bits_array/bits_arr_fill_false.c		\
					bits_array/bits_arr_set_as_true.c		\
					bits_array/bits_arr_set_as_false.c		\
					bits_array/private_convert_to_string.c	\
					buf/buf_get.c							\
					buf/buf_flush.c							\
					buf/buf_create.c						\
					buf/buf_add_chr.c						\
					buf/buf_add_str.c						\
					buf/buf_destroy.c						\
					buf/buf_add_line.c						\
					buf/buf_add_strn.c						\
					buf/private_get_buf.c					\
					buf/buf_printed_count.c					\
					complex/complex_add.c					\
					complex/complex_div.c					\
					complex/complex_sub.c					\
					complex/complex_abs.c					\
					complex/complex_init.c					\
					complex/complex_mult.c					\
					complex/complex_pow2.c					\
					complex/complex_pow3.c					\
					list/lstadd.c							\
					list/lstnew.c							\
					list/lstpop.c							\
					list/lstsize.c							\
					list/lstpurge.c							\
					list/lstappend.c						\
					list/lstdelete.c						\
					list/lstdelone.c						\
					list/lstextend.c						\
					list/lstpopback.c						\
					matrix/matrix_rows.c					\
					matrix/matrix_cols.c					\
					matrix/matrix_copy.c					\
					matrix/matrix_clear.c					\
					matrix/matrix_create.c					\
					matrix/matrix_add_col.c					\
					matrix/matrix_add_row.c					\
					matrix/matrix_destroy.c					\
					memory/ft_memchr.c						\
					memory/ft_memcmp.c						\
					memory/ft_memcpy.c						\
					memory/ft_memset.c						\
					memory/ft_memmove.c						\
					memory/ft_memrchr.c						\
					sorts/ft_bubble_sort.c					\
					string/ft_strchr.c						\
					string/ft_strcmp.c						\
					string/ft_strdup.c						\
					string/ft_strequ.c						\
					string/ft_strlen.c						\
					string/ft_isalpha.c						\
					string/ft_isdigit.c						\
					string/ft_isspace.c						\
					string/ft_strnequ.c						\
					string/ft_strndup.c						\
					string/ft_strjoin.c						\
					utils/gnl.c								\
					utils/itoa.c							\
					utils/to_rad.c							\
					utils/to_ang.c							\
					utils/ft_min.c							\
					utils/ft_max.c							\
					utils/ft_swap.c							\
					utils/ft_atoi.c							\
					utils/ft_error.c						\
					utils/ft_calloc.c						\
					utils/ft_assert.c						\
					utils/bytes_order.c						\
					utils/convert_to_bits.c					\
					utils/private_gnl_list.c				\
					vector/vec_copy.c						\
					vector/vec_size.c						\
					vector/vec_create.c						\
					vector/vec_popback.c					\
					vector/vec_destroy.c					\
					vector/vec_reserve.c					\
					vector/vec_typesize.c					\
					vector/vec_capacity.c					\
					vector/vec_pushback.c					\
					vector/vec_shrink_to_fit.c				\
					warning/warning_add.c					\
					warning/warning_create.c				\
					warning/warning_destroy.c				\
					warning/warning_print.c					\
					warning/private_get_warning_list.c		\
					algorithm/all_of.c						\
					sstream/sstream_add.c					\
					sstream/sstream_clear.c					\
					sstream/sstream_create.c				\
					sstream/sstream_destroy.c				\
					sstream/sstream_empty.c					\
					sstream/sstream_get.c					\
					sstream/sstream_getn.c					\
					sstream/sstream_peek.c					\
					sstream/sstream_set_separator.c			\
					sstream/sstream_skip.c					\
					sstream/sstream_str.c					\
					sstream/sstream_get_str.c				\
					sstream/sstream_getline.c

#-------------------------------------------------------------------------------
#							SOURCE DIRECTORIES
#-------------------------------------------------------------------------------

SRCS_DIR =				./srcs



#-------------------------------------------------------------------------------
#							OBJECTS DIRECTORIES
#-------------------------------------------------------------------------------

DIR_OBJS =				./objs

DIR_BARR_OBJ =			$(DIR_OBJS)/bits_array
DIR_BUF_OBJ =			$(DIR_OBJS)/buf
DIR_COMPLEX_OBJ =		$(DIR_OBJS)/complex
DIR_LIST_OBJ =			$(DIR_OBJS)/list
DIR_MATRIX_OBJ =		$(DIR_OBJS)/matrix
DIR_MEMORY_OBJ =		$(DIR_OBJS)/memory
DIR_SORTS_OBJ =			$(DIR_OBJS)/sorts
DIR_STRING_OBJ =		$(DIR_OBJS)/string
DIR_UTILS_OBJ =			$(DIR_OBJS)/utils
DIR_VECTOR_OBJ =		$(DIR_OBJS)/vector
DIR_WARNING_OBJ =		$(DIR_OBJS)/warning
DIR_ALGORITHM_OBJ =		$(DIR_OBJS)/algorithm
DIR_SSTREAM_OBJ =		$(DIR_OBJS)/sstream

#-------------------------------------------------------------------------------
#						CONVERT SOURCES TO OBJECTS
#-------------------------------------------------------------------------------

OBJS =				$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

#-------------------------------------------------------------------------------
#									INCLUDES
#-------------------------------------------------------------------------------

INCLUDES_DIR =			./includes

#-------------------------------------------------------------------------------
#									FLAGS
#-------------------------------------------------------------------------------

FLAGS =			-g -Wall -Werror -Wextra -I $(INCLUDES_DIR)

FLAGS_DEBUG =	-g -Wall -Werror -Wextra -I $(INCLUDES_DIR)

#-------------------------------------------------------------------------------
#								COMPILING PROJECT
#-------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

#-------------------------------------------------------------------------------
#						ALL NEEDFUL DIRECTORIES CREATING
#-------------------------------------------------------------------------------

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p $(DIR_BARR_OBJ)
	mkdir -p $(DIR_BUF_OBJ)
	mkdir -p $(DIR_COMPLEX_OBJ)
	mkdir -p $(DIR_LIST_OBJ)
	mkdir -p $(DIR_MATRIX_OBJ)
	mkdir -p $(DIR_MEMORY_OBJ)
	mkdir -p $(DIR_SORTS_OBJ)
	mkdir -p $(DIR_STRING_OBJ)
	mkdir -p $(DIR_UTILS_OBJ)
	mkdir -p $(DIR_VECTOR_OBJ)
	mkdir -p $(DIR_WARNING_OBJ)
	mkdir -p $(DIR_ALGORITHM_OBJ)
	mkdir -p $(DIR_SSTREAM_OBJ)

#-------------------------------------------------------------------------------
#							COMPILING OBJECT FILES
#-------------------------------------------------------------------------------

$(DIR_OBJS)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	gcc $(FLAGS) -o $@ -c $<

#-------------------------------------------------------------------------------
#							RECOMPILE PROJECT
#-------------------------------------------------------------------------------

clean:
	@rm -rf $(DIR_OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_DEBUG)

re: fclean all

c: clean

f: fclean

.PHONY: all clean fclean c f debug
