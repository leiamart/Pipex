/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:18:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/16 16:03:17 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_free(char **str, int c)
{
	int i;

	i = 0;
	while(i<c)
	{
	free(str[i])
		i++;
	}
	free(str);
	return (NULL);
}

void	ft_free_cmd(t_args *a)
{
	int 	i;

	i = 0;
	if(a->command1 != NULL)
	{
	while(a->command1[1])
		i++;
	ft_free(a->command1, i);
	}
	i = 0;
	if (a->command2 != NULL)
	{
		while(a->command2[i])
			i++;
		ft_free(a->command2, i);
	}
}

void	*ft_free_arg(t_args *a)
{
	if (a->cmd1 != NULL)
		free(a->cmd1);
	if(a->cmd2 != NULL)
                free(a->cmd2);
	if (a->cmd1_path != NULL)
		free(a->cmd1_path);
	if (a->cmd2_path != NULL)
		free(a->cmd2_path);
	ft_free_cmd(a);
	if (args != NULL)
		free(a);
	return (NULL);

}