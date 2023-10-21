# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:28:41 by lnyamets          #+#    #+#              #
#    Updated: 2023/10/21 17:57:54 by lnyamets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	client/client.c \
		report/report.c \
		utils/util.c \


CFLAGS = -Wall -Werror -Wextra


OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ)
	echo "make Philo succes"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
