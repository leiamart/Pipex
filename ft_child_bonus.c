/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:01 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/18 21:29:47 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_bonus(t_args *a, char **e)
{
	pid_t	p;
	int	pfd[2];
	if (pipe(pfd) == -1)

}


void	ft_child_cmd_bonus(t_args *a, char **e, int pfd)
{
	pid_t	p;
	p = fork();
	if (p==-1)


}
