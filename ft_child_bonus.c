/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:01 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/27 21:42:37 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_bonus(t_arg *a, char **e)
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
		if (execve(a->cmdpath->content, a->command->cmd, e) == -1)
			ft_error_bonus(a, "execve");
	}
	else
	{
		close(pfd[1]);
		if (dup2(pfd[0], STDIN_FILENO) == -1)
			ft_error_bonus(a, "dup2");
		waitpid(p, NULL, 0);
	}
}


void	ft_child_cmd_bonus(t_arg *a, char **e, int pfd)
{
	pid_t	p;
	p = fork();
	if (p==-1)
		ft_error_bonus(a, "dup2");
	close(pfd[0]);
	if (execve(a->cmdpath->content, a->command->cmd, e) == -1)
                        ft_error_bonus(a, "execve");
}
        else
        {
		close(pfd[1]);
                if (dup2(pfd[0], STDIN_FILENO) == -1)
                        ft_error_bonus(a, "dup2");
                waitpid(p, NULL, 0);
		a->cmdpath = a->cmdpath->next;
		a->command = a->command->next;


}

void	ft_error_bonus(t_arg *a, char *e)
{
	perror(e);
	ft_free_arg_bonus(a);
	exit(EXIT_FAILURE);
}
