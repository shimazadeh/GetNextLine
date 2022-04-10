# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shabibol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 17:54:10 by shabibol          #+#    #+#              #
#    Updated: 2022/04/10 22:07:25 by shabibol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = get_next_line.c


SRCS_BONUS = get_next_line.c


OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

$(OBJS_BONUS): $(SRCS_BONUS) $(SRCS)
	gcc $(FLAGS) -c $(SRCS_BONUS) $(SRCS)

all:: $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
