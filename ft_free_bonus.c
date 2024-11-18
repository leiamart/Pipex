/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:09:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/18 21:14:00 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clear_list(t_list **a)
{
	t_list	*aux;

	if (!a)
		return ;
	while (*a)
	{
		aux = (*a)->next;
		free((*a)->content);
		free(*a);
		*a = aux;
	}
	*a = NULL;
}

void	ft_path_free(t_args *a)
{
	t_list	*aux;

	aux = a->cmd_path;
	while (a->cmd_path)
	{
		free(a->cmd_path->content);
		a->cmd_path = a->cmd_path->next;
	}
	a->cmd_path = aux;
	ft_clear_list(&a->cmd_path);
}
