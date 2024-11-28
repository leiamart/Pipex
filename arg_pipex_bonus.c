/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pipex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:44:58 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/28 21:17:30 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_arg_b(t_arg *a, t_list *aux)
{
if (a->heredoc_flag == 1)
		unlink(".heredoc_tmp");
	free(aux);
	ft_printf("Command not found\n");
	ft_free_arg_bonus(a);
	exit(127);
}

char	*ft_cmd_bonus(char *e, char *c)
{
	char	**d;
	char	*str;
	int		i;
	str = ft_substr_b(e, 5, ft_strlen_b(e));
	d = ft_split_b(str, ':');
	free(str);
	i = 0;
	while (d[i] != NULL)
	{
		str = ft_strjoin_b(d[i], c);
		if (access(str, F_OK | X_OK) == 0)
			break ;
		free(str);
		str = NULL;
		i++;
	}
	while (d[i] != NULL)
		i++;
	ft_free_b(d, i);
	return (str);
}

void	ft_files_bonus(t_arg *a)
{
	if (access(a->file1, F_OK) != 0)
	{
		ft_printf("Infile not found\n");
		ft_free_arg_bonus(a);
		exit(1);
	}
	if (access(a->file1, R_OK) != 0)
	{
		ft_printf("Infile permissions denied\n");
		ft_free_arg_bonus(a);
		exit(5);
	}
}

void	ft_start_arg(t_arg *a, int argc, char **argv)
{
	int		i;
	t_cmd	*aux_cmd;
	t_list	*aux;
	t_list	*f;

	i = 1;
	aux = NULL;
	f = NULL;
	ft_initialize_bn(a);
	a->file1 = argv[i++];
	while (i < argc - 1)
	{
		aux_cmd = ft_new_cmd(argv[i++]);
		ft_add_back(&a->command, aux_cmd);
		aux = ft_lstnew(ft_strjoin("/", aux_cmd->cmd[0]));
		if (!f)
			f = aux;
		ft_lstadd_back(&a->cmd, aux);
		a->cmd_n++;
	}
	a->file2 = argv[i];
	a->cmd = f;
}

t_arg	check_args(t_arg *a, char **e)
{
	t_list	*aux;
	t_list	*f;
	int		i;

	aux = a->cmdpath;
	f = a->cmd;
	i = 0;
	while (ft_strncmp_b(e[i], "PATH=", 5) != 0)
		i++;
	ft_files_bonus(a);
	while (f)
	{
		aux = ft_lstnew(ft_cmd_bonus(f->content, e[i]));
		if (aux->content == NULL)
			ft_error_arg_b(a, aux);
		ft_lstadd_back(&a->cmdpath, aux);
		f = f->next;
	}
	return (*a);
}
