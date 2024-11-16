/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:05:09 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/16 16:22:43 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_args *a, char *e)
{
	perror(e);
	free_args(a);
	exit(EXIT_FAILURE);
}

void	ft_child(t_args *a, int pfd[2], char **c)
{
	pid_t p;
	p = fork();

	if (p ==-1)
		ft_error(a, "fork");
	if (p == 0)
	{
		if (dup2(pfd[1], STDOUT_FILENO) == -1)
			ft_error(args, "dup2");
		close(pfd[0]);
		if (execve(a->cmd1_path, a->command1, c) == -1)
			ft_error(a, "execve");
	}
	else
	{
		close(pfd[1]);
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			ft_error(a, "dup2");
		waitpid(p, NULL, 0);
	}
}
