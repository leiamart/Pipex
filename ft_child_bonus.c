/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:01 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/23 19:02:02 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_bonus(t_args *a, char **e)
{
	pid_t	p;
	int	pfd[2];
	if (pipe(pfd) == -1)
	ft_error_bonus(a, "pipe");
	p = fork();
	if (p == -1)
		ft_error_bonus(a, "fork");
	if (p == 0)
	{
		if (dup2(pfd[1], STDOUT_FILENO) == -1)
			ft_error_bonus(a, "dup2");
		close(pfd[0]);
		if (execve(a->cmd_path->content, a->command->cmd, e) == -1)
			ft_error_bonus(a, "execve");
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			ft_error_bonus(a, "dup2");
		waitpid(p, NULL, 0);
	}
}


void	ft_child_cmd_bonus(t_args *a, char **e, int pfd)
{
	pid_t	p;
	p = fork();
	if (p==-1)


}

void	ft_error_bonus(t_args *a, char *e)
{
	perror(e);
	ft_free_arg_bonus(a);
	exit(EXIT_FAILURE);
}
