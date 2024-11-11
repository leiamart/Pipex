/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:52:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/11 18:58:12 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = pipex
CC = clang
CFLAGS = -g -Wall -Wextra -Werror

SOURCES = \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	   $(CC) -g $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)


flcean: clean
	rm -f $(NAME) 

re: flcean all

.PHONY: all bonus clean fclean re

