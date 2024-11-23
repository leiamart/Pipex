/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:07:17 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/23 17:28:54 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "string.h"
# include "stdint.h"
# include "stdarg.h"
# include "errno.h"
# include "sys/wait.h"

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_command;

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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_error(t_args *a, char *e);
void	ft_child(t_args *a, int pfd[2], char **c);
void    ft_infile(t_args *a);
void    ft_outfile(t_args *a);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t destsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_putstr(char *s);
int	ft_putunbr(unsigned int n);
int	ft_putvoid(uintptr_t n);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long long n, char c);
int	ft_putnbr(int n);
int	ft_convert(const char *c, va_list args, int i);
int	ft_printf(const char *str, ...);

void	ft_files(t_args *a);
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

t_command   *ft_new_cmd(char *c);
void    ft_add_back(t_command *n, t_command **l);
t_list  *ft_lstnew(void *content);
void    ft_lstadd_back(t_list **lst, t_list *new);
int     ft_strcmp(const char *s1, const char *s2);

void    ft_clear_list(t_list **a);
void    ft_path_free(t_args *a);
void    *ft_free_b(char **str, int c);
void    *ft_free_arg_bonus(t_args *a);

void    ft_infile_b(t_args *a);
void    ft_outfile_heredoc(t_args *a);
void    ft_outfile_b(t_args *a);

void    ft_initialize_bn(t_args *a);
void    ft_heredoc_init(int argc,t_args *a, char **argv);
void    ft_heredoc(t_args *a, char **argv, int argc);

void    ft_error_arg_b(t_args *a, t_list *aux);
char    *ft_cmd_bonus(char *e, char *c);
void    ft_files_bonus(t_args *a);
void    ft_start_arg(t_args *a, int argc, char **argv);
t_args  check_args(t_args *a, char **e);


int     ft_strncmp_b(const char *s1, const char *s2, size_t n);
size_t  ft_strlen_b(const char *s);
char    *ft_strjoin_b(char const *s1, char const *s2);
char    *ft_substr_b(char const *s, unsigned int start, size_t len);


#endif
