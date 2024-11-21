/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:07:17 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/21 20:14:25 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
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

void	ft_error(t_args *a, char *e);
void	ft_child(t_args *a, int pfd[2], char **c);
void    ft_infile(t_args *a);
void    ft_outfile(t_args *a);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t destsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_files(t_arg *a);
char	*ft_cmd(char *c, char *e);
t_args  ft_arg(t_args *a, char **e);

void    *ft_free(char **str, int c);
void    ft_free_cmd(t_args *a);
void    *ft_free_arg(t_args *a);

void    ft_initialize(t_args *a);
void    ft_parse_arg(t_args *a, char **argv);

void    ft_child_bonus(t_args *a, char **e);
void    ft_child_cmd_bonus(t_args *a, char **e, int pfd);
void    ft_error_bonus(t_args *a, char *e);

void    ft_clear_list(t_list **a);
void    ft_path_free(t_args *a);
void    *ft_free_b(char **str, int c);
void    *ft_free_arg_bonus(t_args *a);

void    ft_infile_b(t_args *a);
void    ft_outfile_heredoc(t_args *a);
void    ft_outfile_b(t_args *a);

void    ft_initialize_bn(t_args *a);
void    ft_heredoc_init(int argc,t_args *a, char **argv);

#endif
