/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:07:17 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/16 14:14:18 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_args
{
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**command1;
	char	**command2;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
}	t_args;





#endif
