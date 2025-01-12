
NAME= push_swap
BONUS= checker

CC= cc

CFLAGS= -g -Wall -Wextra -Werror
INCLUDES= ./includes
LIBFT_DIR= ./libft
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/push_swap.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/push_swap_utils.c $(SRCS_DIR)/stack_init.c \
$(SRCS_DIR)/stack_sorted.c  $(SRCS_DIR)/op/swap.c $(SRCS_DIR)/op/rotate.c $(SRCS_DIR)/op/rev_rotate.c \
$(SRCS_DIR)/op/push.c $(SRCS_DIR)/sort_three.c $(SRCS_DIR)/debug.c $(SRCS_DIR)/sort.c $(SRCS_DIR)/init_stack_cost.c \
$(SRCS_DIR)/define_targets.c $(SRCS_DIR)/push_a_to_b.c $(SRCS_DIR)/push_b_to_a.c

BONUS_SRCS= ./bonus/checker.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/push_swap_utils.c $(SRCS_DIR)/stack_init.c \
$(SRCS_DIR)/stack_sorted.c  $(SRCS_DIR)/op/swap.c $(SRCS_DIR)/op/rotate.c $(SRCS_DIR)/op/rev_rotate.c \
$(SRCS_DIR)/op/push.c $(SRCS_DIR)/debug.c $(SRCS_DIR)/init_stack_cost.c

OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(BONUS_OBJS) -L $(LIBFT_DIR) -lft -o $(BONUS)
clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
