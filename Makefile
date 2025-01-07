
NAME= push_swap

CC= cc


CFLAGS= -g -Wall -Wextra -Werror
INCLUDES= ./includes
LIBFT_DIR= ./libft
FT_PRINTF_DIR= ./ft_printf
LIBFT= $(LIBFT_DIR)/libft.a
FT_PRINTF= $(PRINTF_DIR)/libftprintf.a
SRCS_DIR= ./srcs
SRCS= $(SRCS_DIR)/push_swap.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/push_swap_utils.c $(SRCS_DIR)/stack_init.c \
$(SRCS_DIR)/stack_sorted.c  $(SRCS_DIR)/op/swap.c $(SRCS_DIR)/op/rotate.c $(SRCS_DIR)/op/rev_rotate.c \
$(SRCS_DIR)/op/push.c $(SRCS_DIR)/sort_three.c $(SRCS_DIR)/debug.c


OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
