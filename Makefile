NAME			= pipex
LIBFT			= libft.a

SRCS            =       ft_main.c \
						ft_preprocess.c \
						ft_execution.c \
						utils/ft_clean.c \
						utils/ft_error_1.c \
						utils/ft_error_2.c \
						utils/ft_init.c \
						utils/ft_main_utils.c \
						preprocess/ft_preprocess_allpaths.c \
						preprocess/ft_preprocess_cmd_normal.c \
						preprocess/ft_preprocess_cmd_heredoc.c \
						execution/ft_exec_findpath.c \
						execution/ft_exec_preparefd.c 

SRCS_DIR		= ./srcs
BUILD_DIR       = ./.build
INCLUDES_DIR	= ./headers
LIBFT_DIR		= ./libft

OBJS			= $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS			:= $(OBJS:%.c=%.o)
SRCS			:= $(addprefix $(SRCS_DIR)/, $(SRCS))

CC				= cc
CFLAGS          = -Wall -Werror -Wextra
HFLAGS			= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/includes

all					: ${NAME}

${NAME}         	: ${OBJS}
			${CC} $(OBJS) -o $(NAME) -L./libft/ -lft

${BUILD_DIR}/%.o	:$(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
			${CC} ${CFLAGS} $(HFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT)			:
			make -C libft

clean			:
			make -C $(LIBFT_DIR) clean
			rm -rf ${OBJS}

fclean			: clean
			rm -rf ${NAME} $(LIBFT_DIR)/libft.a

re				: fclean all

.PHONY			: all clean fclean re
