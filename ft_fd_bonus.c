/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:07:31 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/19 21:43:58 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile_b(t_args *a)
{
	a->fd1 = open(a->file1, O_RDONLY);
	if(a->fd1 < 0)
		ft_error_bonus(a, "open");
}
