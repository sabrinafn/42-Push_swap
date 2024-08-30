NAME := push_swap

NAMEBONUS := checker

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := push_swap.h

CFILES :=	main.c \
			ft_sort.c \
			ft_calculations.c \
			ft_check_args.c \
			ft_linked_list_manager.c \
			ft_linked_list_utils.c \
			ft_set_index.c \
			ft_utils.c \
			ft_sort_small.c \
			ft_calculate_cost.c \
			ft_functions_to_rotate.c \
			ft_ops_push.c \
			ft_ops_reverse_rotate.c \
			ft_ops_rotate.c \
			ft_ops_swap.c

CBONUS :=	./bonus/main.c \
			./bonus/ft_linked_list_manager.c \
			./bonus/ft_utils.c \
			./bonus/ft_check_args.c \
			./bonus/ft_ops_push.c \
			./bonus/ft_ops_swap.c \
			./bonus/ft_ops_rotate.c \
			./bonus/ft_ops_reverse_rotate.c \
			./bonus/get_next_line.c \
			./bonus/get_next_line_utils.c

OFILES := $(CFILES:.c=.o)

OBONUS := $(CBONUS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $^ -o $@

$(NAMEBONUS): $(OBONUS)
	$(CC) $(FLAGS) $^ -o $@

all: $(NAME)

bonus: $(NAMEBONUS)

clean:
	rm -f $(OFILES) $(OBONUS)

fclean:
	rm -f $(OFILES) $(NAME) $(OBONUS) $(NAMEBONUS)

re: fclean all

.PHONY: all clean fclean re
