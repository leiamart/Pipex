/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:52:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/19 21:40:56 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = pipex
CC = clang
CFLAGS = -g -Wall -Wextra -Werror

SOURCES = \
arg_pipex.c\
ft_child_process.c\
ft_free.c\
ft_printf.c\
ft_split.c\
ft_utils_printf.c\
pipex.c\
utils_pipex.c\
pipex_utils.c\

SOURCES_BONUS = \
ft_child_bonus.c\
ft_fd_bonus.c\
ft_free_bonus.c\
ft_here_doc_bonus.c\
utils_bonus.c\


OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) -g $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	   $(CC) -g $(FLAGS) $(OBJECTS) -o $(NAME)

$(NAME_BONUS) : $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)


flcean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: flcean all

.PHONY: all bonus clean fclean re

