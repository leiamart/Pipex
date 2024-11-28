/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:08:46 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/28 22:34:51 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	*ft_new_cmd(char *c)
{
	t_command	*new;

	new = NULL;
	new = malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	if (new)
	{
		new->cmd = ft_split(c, ' ');
		new->next = NULL;
	}
	return (new);
}

void    ft_add_back(t_command *n, t_command **l)
{
        t_command   *b;

        b = *l;
        if (!b)
                *l = n;
        else
        {
                while (b->next)
                        b = b->next;
                b->next = n;
        }
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last)
		last -> next = new;
	else
		*lst = new;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
