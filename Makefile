
NAME = minishell

SRCS_DIR = srcs/

SRC_MAIN = $(addprefix $(SRCS_DIR)main/, minishell.c print_prompt.c \
	sig_handler.c get_input.c parse_and_execute.c)

SRC_LEXER = $(addprefix $(SRCS_DIR)lexer/, get_token.c copy_token_to_buf.c \
	tokenize.c is_space.c check_syntax.c copy_arg_token_to_buf.c)

SRC_SOURCE = $(addprefix $(SRCS_DIR)source/, source.c peek_word.c)

SRC_EXECUTE = $(addprefix $(SRCS_DIR)execute/, execute.c ft_cd.c ft_echo.c ft_pwd.c ft_string.c \
	ft_env.c ft_unset.c ft_return_with_error.c ft_export.c ft_export_print.c comand_cond.c \
	ft_execve.c simple_execute.c hard_execute.c utils.c)

SRC_TOKENS_SRC = $(addprefix $(SRCS_DIR)tokens_src/, tokens_src.c \
	is_exhasted.c move_to_cmd_end.c)

SRC_TOKEN = $(addprefix $(SRCS_DIR)token/, token.c)

SRC_EXPAND = $(addprefix $(SRCS_DIR)expand/, expand_arg.c \
	single_quated_str_exp_and_cpy_to_buf.c unquated_str_exp_and_cpy_to_buf.c \
	dollar_exp_and_cpy_to_buf.c get_var_name.c is_var_name_char.c \
	double_quated_str_exp_and_cpy_to_buf.c)

SRC_PARSER = $(addprefix $(SRCS_DIR)parser/, parse_commands.c \
	get_command.c parse_args.c parse_redirects.c)

SRC_ERROR = $(addprefix $(SRCS_DIR)error/, ft_print_error.c ft_exit_with_error.c)

SRC_COMAND = $(addprefix $(SRCS_DIR)comand/, free_cmd.c)

SRC_UTILS = $(addprefix $(SRCS_DIR)utils/, print_tokens.c \
	print_env_key_vals.c)

SRC_BUFFER = $(addprefix $(SRCS_DIR)buffer/, char_buffer.c)

SRC_ENV_VARS = $(addprefix $(SRCS_DIR)env_vars/, env_kv_funcs.c sort.c \
	create_env_kv_lst.c create_export_env_vars_arr.c)

SRCS = $(SRC_MAIN) $(SRC_LEXER) $(SRC_SOURCE) $(SRC_UTILS) $(SRC_EXECUTE) \
	$(SRC_TOKENS_SRC) $(SRC_TOKEN) $(SRC_EXPAND) $(SRC_ERROR) $(SRC_PARSER) \
	$(SRC_COMAND) $(SRC_BUFFER) $(SRC_ENV_VARS)

HEADERS = $(addprefix $(SRCS_DIR), main/minishell.h utils/utils.h \
	lexer/lexer.h source/source.h execute/ft_minishell.h \
	tokens_src/tokens_src.h token/token.h expand/expand.h \
	parser/parse_commands.h error/error.h comand/comand.h buffer/char_buffer.h \
	env_vars/env_vars.h)    

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c -g

INCLUDES_DIRS = -I$(SRCS_DIR)libft -I$(SRCS_DIR) -I$(SRCS_DIR)main \
	-I$(SRCS_DIR)utils -I$(SRCS_DIR)lexer -I$(SRCS_DIR)source \
	-I$(SRCS_DIR)execute -I$(SRC_DIR)tokens_src.h -I$(SRC_DIR)token/token.h \
	-I$(SRC_DIR)expand/expand.h -I$(SRC_DIR)parser/parse_commands.h \
	-I$(SRC_DIR)error/error.h -I$(SRC_DIR)comand/comand.h \
	-I$(SRC_DIR)buffer/buffer.h

LIBFT_ARC = $(SRC_DIR)libft/libft.a

.PHONY: all clean fclean re

all: libft $(NAME)

libft:
	make -C srcs/libft

$(NAME): $(OBJS) srcs/libft/libft.a
	$(CC) -o $(NAME) -Lsrcs/libft -lft $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES_DIRS) $< -o $@

clean:
	make clean -C srcs/libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C srcs/libft
	rm -f $(NAME)

re: fclean all

run: all
	./minishell

remove_odd_objs:
	find . -name "*.o" -type f -delete