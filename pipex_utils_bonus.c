/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:23:58 by leiamart          #+#    #+#             */
/*   Updated: 2024/11/23 17:23:19 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *ft_substr_b(char const *s, unsigned int start, size_t len)
{
        size_t  i;
        size_t  c;
        char    *p;

        i = 0;
        c = 0;
        if (start > ft_strlen(s))
                len = 0;
        else if (len > (ft_strlen(s) - start))
                len = ft_strlen(s) - start;
        p = malloc(len + 1);
        if (!p)
                return (NULL);
        while (s[i])
        {
                if (i >= start && c < len)
                {
                        p[c] = s[i];
                        c++;
                }
                i++;
        }
        p[c] = '\0';
        return (p);
}

char    *ft_strjoin_b(char const *s1, char const *s2)
{
        char    *j;
        int             i;
        size_t  size;

        if (!s1 || !s2)
                return (NULL);
        size = ft_strlen(s1) + ft_strlen(s2) + 1;
        j = (char *)malloc(size);
        if (!j)
                return (NULL);
        i = 0;
        while (s1[i] != '\0')
        {
                j[i] = s1[i];
                i++;
        }
        j[i] = '\0';
        ft_strlcat(j, s2, size);
        return (j);
}

size_t  ft_strlen_b(const char *s)
{
        size_t  i;

        i = 0;
        while (((char *)s)[i] != '\0')
        {
                i++;
        }
        return (i);
}

int	ft_strncmp_b(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2 [i]) && (s1[i] && s2[i] != '\0') && (i < n))
		i++;
	{
		if (i != n)
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		return (0);
	}
}



