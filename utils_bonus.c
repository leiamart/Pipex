/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:08:46 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/18 21:22:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_new_cmd(char *c)
{
	t_cmd	*new;

	new = NULL;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (new)
	{
		new->cmd = ft_split(c, ' ');
		new->next = NULL;
	}
	return (new);
}

void    ft_add_back(t_cmd *n, t_cmd **l)
{
        t_cmd   *b;

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

