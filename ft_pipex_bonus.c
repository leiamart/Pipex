/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:08:04 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/28 22:42:35 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_b(t_arg *a, char **e)
{
	int	pfd[2];
	pid_t p;

	f (p(pfd) == -1)
		ft__error_bonus(a, "pipe");
	if (dup2(a->fd1, STDIN_FILENO) == -1)
		ft__error_bonus(a, "dup2");
	ft_child_cmd_bonus(a, pfd, e);
	if (dup2(a->fd2, STDOUT_FILENO) == -1)
		ft_error_bonus(a, "dup2");
	p = fork();
	if (p == -1)
		ft_error_bonus(a, "fork");
	if (p == 0)
	{
		if (execve(a->cmdpath->content, a->command->cmd, e) == -1)
			ft_error_bonus(a, "execve");
	}
	else
	{
		waitpid(p, NULL, 0);
	}
}

void	ft_pipex_finish(t_arg *a, char **e)
{
	pid_t	p;

	if (dup2(a->fd2, STDOUT_FILENO) == -1)
		ft_error_bonus(a, "dup2");
	p = fork();
	if (p == -1)
		ft_error_bonus(a, "fork");
	if (p == 0)
	{
		if (execve(a->cmdpath->content, a->command->cmd, e) == -1)
			ft_error_bonus(a, "execve");
	}
	else
	{
		waitpid(p, NULL, 0);
		a->cmd = a->firstcmd;
		a->cmdpath = a->firstpath;
		a->command = a->firstcommand;
	}
}

t_arg	*ft_start(t_arg *a, char **argv, int argc, char **e)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		ft_heredoc(a, argv, argc);
		*a = ft_args_b(a, e);
		ft_outfile_b(a);
	}
	else
	{
		ft_srtarted_arg(a, argv, argc);
		*a = ft_args_b(a, e);
		ft_infile_b(a);
		ft_outfile_b(a);
	}
	a->firstcmd = a->cmd;
	a->firstpath = a->cmdpath;
	a->firstcommand = a->command;
	return (a);
}


void	ft_pipex_bonus(t_args *a, int argc, char **e)
{
	int		i;

	i = 2;
	if (dup2(a->fd1, STDIN_FILENO) == -1)
		ft_error_bonus(a, "dup2");
	while (i < argc - 2)
	{
		ft_child_bonus(a, e);
		a->index++;
		if (a->command->next)
		{
			a->command = a->command->next;
			a->cmd = a->cmd->next;
			a->cmdpath = a->cmdpath->next;
		}
		i++;
	}
	ft_pipex_finish(a, e);
}

int	main(int argc, char **argv, char **e)
{
	t_arg	*a;

	if (argc >= 5)
	{
		a = malloc(sizeof(t_arg));
		if (!a)
			return (1);
		a = ft_start(a, argv, argc, e);
		if (argc == 5)
			ft_pipex_b(a, e);
		else
			ft_pipex_bonus(a, argc, e);
		if (ft_strcmp(argv[1], "here_doc") == 0)
			unlink(".heredoc_tmp");
		ft_arg_bonus(a);
	}
	else
	{
		ft_printf("Error: Few arguments passed\n");
		exit(1);
	}
	return (0);
}
