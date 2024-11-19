/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:09:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/19 21:50:51 by leiamart         ###   ########.fr       */
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

void	*ft_free_b(char **str, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
	free(str[i]);
	i++;
	}
	free(str);
	return (NULL);
}

void	*ft_free_arg_bonus(t_args *a)
{
	int		i;
	t_cmd	*aux;

	ft_clear_list(&a->cmd);
	if (a->cmd_path)
		ft_clear_list(&a->cmd_path);
	while (a->command)
	{
		i = 0;
		while (a->command->cmd[i])
			i++;
		ft_free_b(a->command->cmd, i);
		aux = a->command->next;
		free(a->command);
		a->command = aux;
	}
	free(a);
	return (NULL);
}
