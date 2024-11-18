/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:03:42 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/18 21:07:11 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialize_bn(t_args *a)
{
	a->cmd = NULL;
	a->cmd_path = NULL;
	a->command = NULL;
	a->first_cmd = NULL;
	a->first_path = NULL;
	a->first_command = NULL;
	a->file1 = NULL;
	a->file2 = NULL;
	a->limiter = NULL;
	a->cmd_nbr = 0;
	a->index = 0;
	a->fd1 = 0;
	a->fd2 = 0;
	a->heredoc_flag = 0;

}

void	ft_heredoc_init(int argc,t_args *a, char **argv)
{

}
