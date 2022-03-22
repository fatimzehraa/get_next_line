/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:03:57 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/22 18:47:19 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include<stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strncpy(s, s1, s1_len);
	ft_strncpy(s + s1_len, s2, s2_len);
	free(s1);
	return (s);
}

int	is_new_line(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_until_newline(int fd, char *over_line)
{
	int		read_ret;
	char	*buffer;

	buffer = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!is_new_line(over_line))
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
			break ;
		if (read_ret == -1)
		{
			free(buffer);
			free(over_line);
			return (NULL);
		}
		buffer[read_ret] = 0;
		over_line = ft_strjoin(over_line, buffer);
		if (over_line)
			break ;
	}
	free(buffer);
	return (over_line);
}
